# opencv_simple_cuda_test
A simple tool to verify that CUDA driver are correctly installed and OpenCV can use it

##Instruction:
* compile: ```$ g++ cuda_test.cpp -o cuda_test -lopencv_core -lopencv_gpu```
* run: ```$ ./cuda_test```

If everything is correct you should get something like this:
```
CUDA enabled devices: 1

Device #0:
==========
GM20B
Tot memory: 3853MB
Free memory: 1933MB

CUDA device active: 0
```
This is the output of the test executed on Nvidia Jetson TX1 board
