/*
 * =====================================================================================
 *
 *       Filename:  testProps.cpp
 *
 *    Description:  Main program to test the cudaProps class.
 *
 *        Version:  1.0
 *        Created:  09/18/2015 03:31:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Koufos (APK), Alexander.P.Koufos@leidos.com
 *   Organization:  Leidos
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <cuda_runtime.h>
#include "cudaProps.h"

using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
  int device = 0;
  CudaGetProps cudaDevs;

  cudaDevs.displayNumDevices();
  
  do
  {
    cout << "Which device would you like to get information about? (-1 to exit) ";
    cin >> device;

    if ( device >= 0 )
    {
      cudaDevs.displayDeviceMaxThreads(device);
    }
    cout << endl;
  } while ( device != -1 );			/* -----  end do-while  ----- */

  return EXIT_SUCCESS;
}			/* ----------  end of function main  ---------- */
