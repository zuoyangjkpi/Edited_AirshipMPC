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

import struct

class DetectionInfo(object):
    decoder = struct.Struct("=Bf4h")
    label = 0
    score = 0.0
    xmin = 0
    xmax = 0
    ymin = 0
    ymax = 0
    def __init__(self,data=None):
        if data is None:
            self.label=0
            self.score=0.0
            self.xmin=0
            self.xmax=0
            self.ymin=0
            self.ymax=0
        elif isinstance(data,tuple) or isinstance(data,list):
            ((self.label,self.score),
            (self.xmin,self.ymin),
            (self.xmax,self.ymax)) = data
        else:
            self.decode(data)

    def decode(self,data,offset=0):
        (self.label,self.score,
            self.xmin,self.xmax,
            self.ymin,self.ymax) = self.decoder.unpack_from(data,offset)

    def encode(self,to,offset=0):
        return self.decoder.pack_into(to,offset,int(self.label),float(self.score),int(self.xmin),int(self.xmax),int(self.ymin),int(self.ymax))

    def asHash(self):
        return{'label':self.label,'score':self.score,
                'xmin':self.xmin,'xmax':self.xmax,
                'ymin':self.ymin,'ymax':self.ymax}

class DetectionResults(object):
    decoder=struct.Struct("=H")
    detection=[]

    def __init__(self,data=None):
        if data is None:
            self.detection=[]
        else:
            self.decode(data)
    
    def decode(self,data):
        (count,) = self.decoder.unpack_from(data,0)
        offset=2
        self.detection=[]
        for r in range(count):
            a = DetectionInfo()
            a.decode(data,self.decoder.size+r*a.decoder.size)
            self.detection.append(a)

    def encode(self):
        if not len(self.detection):
            return self.decoder.pack(0)
        else:
            res=bytearray(self.decoder.size+len(self.detection)*self.detection[0].decoder.size)
            self.decoder.pack_into(res,0,len(self.detection))
            for i,det in enumerate(self.detection):
                det.encode(res,self.decoder.size+i*det.decoder.size)
            return res

    def asHash(self):
        return {'count':len(self.detection),'detection':[ det.asHash() for det in self.detection ]}



