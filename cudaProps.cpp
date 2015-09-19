/*
 * =====================================================================================
 *
 *       Filename:  cudaProps.cpp
 *
 *    Description:  C++ file to define CudaGetProps class.
 *
 *        Version:  1.0
 *        Created:  09/18/2015 03:43:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Koufos (APK), Alexander.P.Koufos@leidos.com
 *   Organization:  Leidos
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "cudaProps.h"

using namespace std;

// Default constructor for getting CUDA enabled devices
CudaGetProps::CudaGetProps()
{
  cudaGetDeviceCount( &dev_count);
  //dev_props = new cudaDeviceProp[dev_count];
  dev_props = (cudaDeviceProp*) malloc(dev_count*sizeof(cudaDeviceProp));
  
  for ( int i = 0; i < dev_count; i++ )
  {
    cudaGetDeviceProperties( dev_props, i );
  }
} /* End default constructor */

CudaGetProps::~CudaGetProps()
{
  free(dev_props);
}

int CudaGetProps::getNumDevices()
{
  return dev_count;
} 

int CudaGetProps::getDeviceMaxThreads( int i)
{
  return dev_props[i].maxThreadsPerBlock;
}

int CudaGetProps::getDeviceSHMPerBlock( int i)
{
  return dev_props[i].sharedMemPerBlock;
}

string CudaGetProps::getDeviceName( int i)
{
  return dev_props[i].name;
} 

void CudaGetProps::displayNumDevices()
{
  cout << "\nThe number of CUDA enabled devices on this machine is " <<
    getNumDevices() << endl << endl;
}

void CudaGetProps::displayDeviceMaxThreads( int i)
{
  cout << "The max threads per block of device " << getDeviceName(i) << " is "
       << getDeviceMaxThreads(i) << endl;
}

void CudaGetProps::displayDeviceSHMPerBlock( int i)
{
  cout << "The amount of shared memory per block of device " << getDeviceName(i)
       << " is "  << getDeviceSHMPerBlock(i) << endl;
}
