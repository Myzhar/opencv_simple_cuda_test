#include <opencv2/core.hpp>

#if (CV_MAJOR_VERSION==2)
#include <opencv2/gpu/gpu.hpp>
using namespace cv::gpu;
#elif (CV_MAJOR_VERSION==3)
#include <opencv2/core/cuda.hpp>
using namespace cv::cuda;
#endif

#include <stdlib.h>
#include <iostream>

using namespace std;

int main( )
{
    cout << endl;
    cout << "OpenCV version"<< endl;
    cout << "--------------"<< endl;
    cout << "Major version:    " << CV_MAJOR_VERSION << endl;
    cout << "Minor version:    " << CV_MINOR_VERSION << endl;
    cout << "Subminor version: " << CV_SUBMINOR_VERSION << endl << endl;
  
    int devCount;

    devCount = getCudaEnabledDeviceCount();

    cout << "* Total CUDA enabled devices: " << devCount << endl;

    if( devCount<1 )
    {
        cout << endl << "No GPU support. Possible causes:" << endl;
        cout << " * System does not have a CUDA enabled card." << endl;
        cout << " * No CUDA driver installed." << endl;
        cout << " * OpenCV compiled before CUDA toolkit installation" << endl;
        cout << " * OpenCV compiled with CUDA flag disabled" << endl << endl;
        return 0;
    }

    for( int i=0; i<devCount; i++ )
    {
        DeviceInfo devInfo(i);

        cout  << endl << "Device #" << i << ":" << endl;
        cout << "==========" << endl;

        printShortCudaDeviceInfo(i);
        cout << "* Tot memory: " << devInfo.totalMemory()/(1024*1024) << "MB" << endl;
        cout << "* Free memory: " << devInfo.freeMemory()/(1024*1024) << "MB" << endl;
        cout << "-" << endl;
        cout << "* Complete information:" << endl;
        printCudaDeviceInfo(i);


    }

    cout  << "* active CUDA device id: " << getDevice() << endl  << endl;

    return 0;
}

