#!/usr/bin/python3 -u
# Copyright (c) 2022, Max Planck Institute for Intelligent Systems. All rights reserved.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import argparse
import numpy as np
from collections import OrderedDict
import torch
import torch.utils.data
import re
import select
import socket
import sys
import binary_structs
import utils
#import cv2
#cv2.namedWindow('Seen', cv2.WINDOW_NORMAL)
#cv2.resizeWindow('Seen', 224, 224)

use_cuda = torch.cuda.is_available()
device = torch.device("cuda" if use_cuda else "cpu")

parser = argparse.ArgumentParser(description='Evaluate Network')
parser.add_argument('-p', '--port', type=int, action='store', default='9900' )
parser.add_argument('-t', '--threshold', type=float, action='store', default=0.01 )
args = parser.parse_args()
PORT = args.port
THRESHOLD = float(args.threshold)
SIZE=300
BUFFERSIZE=SIZE*SIZE*3 #BGR data, 8 bit per channel

print("Loading Model ")
#model = torch.hub.load('robot-perception-group/NVIDIADeepLearningExamplesFork:aircap', 'nvidia_ssd')
import model 
model=model.SSD300(backbone=model.ResNet('resnet34'))
weights=torch.hub.load_state_dict_from_url('https://keeper.mpdl.mpg.de/f/bd06ac1f6cf84da8b749/?dl=1', map_location=lambda storage, loc: storage, file_name='ssd.pt')['model']
model.load_state_dict(weights)
model = model.to(device)
model.eval()


hardEmpty = torch.empty((0),dtype=torch.float32,requires_grad=False).to(device)
hardZero = torch.zeros(1,dtype=torch.long,requires_grad=False).to(device)
dboxes = utils.dboxes300_coco()
encoder = utils.Encoder(dboxes)


# SSD Multibox non maximum supporession is implemented wrong and horribly inefficient.

def inference(prediction, min_conf=0.01, nms_iou=0.5):
    loc_p,conf_p = prediction
    loc_p = loc_p.detach().requires_grad_(False)
    conf_p = conf_p.detach().requires_grad_(False) # we don't backpropagate through this

    loc_decoded,conf_p=encoder.scale_back_batch(loc_p,conf_p)

    labels = conf_p[:,:,1:] # ignore label 0 (background)

    labelmask = labels >= min_conf

    results=[]
    #nms needs to be done the slow way 
    for frame in range(labels.shape[0]):
        lboxes=[hardEmpty.view(0,3,2)]
        for label in range(labels.shape[2]):
            framelabelscores=labels[frame,:,label]
            frameboxes=loc_decoded[frame]
            indices=labelmask[frame,:,label].nonzero().flatten() #this is only needed because of buggy pytorch ONNX export, which doesn't like boolean mask access
            scores = torch.cat((framelabelscores[indices],hardZero.float()),0)
            boxes = torch.cat((frameboxes[indices],hardZero.float().view(1,1).expand(1,4)),0)

            # do non maximum suppression
            index = scores.argsort(descending=True)[0:200] # only the 200 highest scores per class are kept, speeds things up in a worst case scenario
            scores=scores[index]
            boxes=boxes[index]
            overlapping = (utils.calc_iou_tensor(boxes,boxes) > nms_iou) # 2x2 boolean matrix of all boxes with too high jaccard overlap - each row has at least one True value on diagonal
            scorematrix = overlapping.float() * scores[:,None]       #this replaces the boolean values with the scores of the column-box

            keep = (scorematrix.max(dim=0)[0] == scores).nonzero().view(-1)

            scores = scores[keep]
            boxes = boxes[keep].view(-1,2,2)
            # this is serialisable for export to ONNX

            score_enc = torch.cat( (scores.unsqueeze(1)*0 + label + 1, scores.unsqueeze(1)), 1).unsqueeze(1)
            boxes = torch.cat( (score_enc,boxes), 1)
            # boxes are now of shape [detections][3][2]
            # with content [[class,conf],[x1,y1],[x2,y2]], ...
            lboxes.append(boxes)
        lboxes = torch.cat( lboxes,0 )
        index = lboxes[:,0,1].sort(descending=True)[1]
        results.append(lboxes[index].contiguous())

    return results



def process(data,metainfo):
    # convert data to tensor, via numpy, and send to GPU
    nump=np.frombuffer(data,dtype=np.uint8,count=(SIZE*SIZE*3))
    #frame = torch.from_numpy(
    #            np.frombuffer(data,dtype=np.uint8,count=(SIZE*SIZE*3))
    #        ).view((SIZE,SIZE,3)).to(device).permute(2,0,1).unsqueeze(0).float() * (1.0/255)
    frame = (torch.from_numpy(
                np.frombuffer(data,dtype=np.uint8,count=(SIZE*SIZE*3))
            ).view((SIZE,SIZE,3)).to(device).permute(2,0,1).unsqueeze(0).float() * (1.0/127)) - 1.0
    # normalization used for torchvision pretrained models
    #frame = (torch.from_numpy(
    #            np.frombuffer(data,dtype=np.uint8,count=(SIZE*SIZE*3))
    #        ).view((SIZE,SIZE,3)).to(device).permute(2,0,1).unsqueeze(0).float() * (1.0/255))
    #mean = torch.tensor([0.485,0.456,0.406]).to(device)
    #std = torch.tensor([0.229,0.224,0.225]).to(device)
    #frame.sub_(mean[:,None,None]).div_(std[:,None,None])

    #seen=(frame.squeeze(0).permute(1,2,0).clone() * 255.0).type(torch.uint8).numpy()
    #cv2.imshow("Seen",seen)
    #cv2.waitKey(1)
    #hx = metainfo['Hx']
    y0 = model(frame)
    y = inference(y0)[-1]

    #metainfo['Hx'] = model.hx

    result_mask=y[:,0,1] > THRESHOLD # min confidence score
    results = y[result_mask].cpu()
    binresults = binary_structs.DetectionResults()
    for box in results:
        box[1:3,:] = torch.clamp(box[1:3,:],-1,2) * SIZE # scale boxes by SIZE
        binresults.detection.append(binary_structs.DetectionInfo(box.tolist()))
    return binresults.encode()

print("Setting up TCP server on port %i"%PORT)

server = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
server.setblocking(0)
server.bind(('',PORT))
server.listen()

#for select call:
inputs=[server]
outputs=[]
output_queues={}
input_queues={}
conninfo={}

while inputs:
    readable, writeable, other = select.select( inputs, outputs, inputs) # waits for incoming connections OR data

    # flush data first so it doesn't accumulate
    for fd in writeable:
        if len(output_queues[fd]):
            print('.')
            try:
                fd.send(output_queues[fd].pop())
            except:
                print("Write failed to %s"%str(conninfo[fd]['address']))
        else:
            outputs.remove(fd)

    # read new data
    for fd in readable:
        if fd is server:
            conn,address = fd.accept()
            conn.setblocking(0)
            inputs.append(conn)
            output_queues[conn] = []
            input_queues[conn] = bytearray()
            conninfo[conn] = {'address':address,'Hx':None}
            print("Accepted connection from %s"%(str(address)))
        else:
            try:
                data = fd.recv(BUFFERSIZE)
            except:
                data = False

            if data:
                input_queues[fd] += data
                if (len(input_queues[fd])>=BUFFERSIZE):
                    output_queues[fd].insert(0,process(input_queues[fd],conninfo[fd]))
                    input_queues[fd]=input_queues[fd][BUFFERSIZE:]
                    if fd not in outputs:
                        outputs.append(fd)
            else:
                print("Closed connection to %s"%str(conninfo[fd]['address']))
                if fd in outputs:
                    outputs.remove(fd)
                inputs.remove(fd)
                fd.close()
                del output_queues[fd]
                del input_queues[fd]
                del conninfo[fd]

    # close broken fds
    for fd in other:
        inputs.remove(fd)
        if fd in outputs:
            outputs.remove(fd)
        fd.close()
        if output_queues[fd]:
            del output_queues[fd]
        if input_queues[fd]:
            del input_queues[fd]
        if conninfo[fd]:
            del conninfo[fd]



exit(1)
