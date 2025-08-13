# pytorch_ssd_server
SSD Multibox server in pytorch for AIRCAP

This is a replacement for caffe ssd_server utilizing pytorch - for use with AIRCAP.
It utilizes https://github.com/NVIDIA/DeepLearningExamples/tree/master/PyTorch/Detection/SSD
but with vastly superior non maximum suppression using tensor operations on GPU only (as opposed to a python loop over all detections)

usage:
1. Install pytorch with GPU support (see pytorch documentation)
2. python3 server.py
3. When tracking people, in AIRCAP change default class from 15 (VOCPascal person) to 1 (MSCOCO person)
