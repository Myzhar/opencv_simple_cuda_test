#include <opencv2/core/core.hpp>
#include <opencv2/gpu/gpu.hpp>
#include <iostream>

using namespace std;

int main( )
{
    int devCount = cv::gpu::getCudaEnabledDeviceCount();

    cout << "CUDA enabled devices: " << devCount << endl;

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
        cv::gpu::DeviceInfo devInfo(i);

        cout  << endl << "Device #" << i << ":" << endl;
        cout << "==========" << endl;

        cout << devInfo.name() << endl;
        cout << "Tot memory: " << devInfo.totalMemory()/(1024*1024) << "MB" << endl;
        cout << "Free memory: " << devInfo.freeMemory()/(1024*1024) << "MB" << endl;
    }

    cout  << endl << "CUDA device active: " << cv::gpu::getDevice() << endl  << endl;

    return 0;
}

