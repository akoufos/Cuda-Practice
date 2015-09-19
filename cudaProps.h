/*
 * =====================================================================================
 *
 *       Filename:  cudaProps.h
 *
 *    Description:  Header file for obtaining important CUDA based properties
 *    of a machine.
 *
 *        Version:  1.0
 *        Created:  09/18/2015 03:18:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Koufos (APK), Alexander.P.Koufos@leidos.com
 *   Organization:  Leidos
 *
 * =====================================================================================
 */

#ifndef  cudaProps_INC
#define  cudaProps_INC

#include <cuda_runtime.h>
#include <string>

using namespace std;

/*
 * =====================================================================================
 *        Class:  CudaGetProps
 *  Description:  
 *  Class that gets the properties of CUDA devices on your current machine.
 * =====================================================================================
 */
class CudaGetProps
{
  public:
    /* ====================  LIFECYCLE     ======================================= */
    CudaGetProps();     /* constructor */
    ~CudaGetProps();    /* destructor */

    /* ====================  ACCESSORS     ======================================= */
    /* Gets the number of CUDA enabled devices on the machine */
    int getNumDevices();
    /*  Gets the maximum threads/block of the CUDA device */
    int getDeviceMaxThreads( int );
    /* Gets the amount of shared memory/block of the device */
    int getDeviceSHMPerBlock( int );
    /* Gets the CUDA enabled device name */
    string getDeviceName( int );
    /* Displays the number of CUDA enabled devices */
    void displayNumDevices();
    /*  Displays the thread information of the CUDA enabled device */
    void displayDeviceMaxThreads( int );
    /*  Displays the shared memory information of the CUDA enabled device */
    void displayDeviceSHMPerBlock( int );

  private:
    /* ====================  DATA MEMBERS  ======================================= */
    int dev_count; // Number of CUDA enabled devices on the machine
    cudaDeviceProp *dev_props; // Properties of the CUDA enabled devices

}; /* -----  end of class CudaGetProps  ----- */

#endif   /* ----- #ifndef cudaProps_INC  ----- */
