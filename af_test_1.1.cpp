/*
This code test ArrayFire array manipulation.

g++ -std=c++11 af_test_1.cpp -laf
g++ -std=c++11 af_test_1.cpp -lafcuda
g++ -std=c++11 af_test_1.cpp -lafopencl
 */

#include <arrayfire.h>
#include<cstdio>
#include<cstdlib>

using namespace af; // namespace for ArrayFire library

//create a wrapper for benchmarking
static array A;
static array B;
static void timingmatrix()
{
  B = matmul(A,A);
  B.eval();
}


int main(int argc, char *argv[])
{

  try{
    //Select a device and display arrayfire info
    int device = argc > 1 ? atoi(argv[1]) : 0;
    //af::setBackend(AF_BACKEND_OPENCL);
    //af::setBackend(AF_BACKEND_CPU);
    //af::setBackend(AF_BACKEND_CUDA);
    af::setDevice(device);
    af::info();

    int n=2048;
    A = randu(n,n);

    double timer = timeit(timingmatrix);  //seconds
    double gflops = 2.0* powf(n,3) / (timer*1e9);
    printf("Matrix A %d x %d\n", n, n);
    printf("Time : %lf\n", timer);
    printf("GFLOPS: %lf\n", gflops);
        
  }catch(af::exception& e){
    
    fprintf(stderr, "%s\n", e.what() );
    throw;
    
  }

  return 0;
  
}
