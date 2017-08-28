# ArrayFire-sample
Sample coding using ArrayFire v3.4.2

Warning!
This test results are entirely my experiment. Your milage may vary.

Box: Ubuntu 16.04
GPU: Nvidia GTX 780M
Compiler: Fortran-> gfortran 5.4.0
          C/C++ -> gcc 5.4.0 (g++ compiled using std=c++11)


Performance from using ArrayFire v3.4.2:

ArrayFire v3.4.2 (CUDA, 64-bit Linux, build 2da9967)
Platform: CUDA Toolkit 8, Driver: 375.82
[0] GeForce GTX 780M, 4037 MB, CUDA Compute 3.0
Matrix A 2048 x 2048
Time : 0.013923
GFLOPS: 1233.939065

Performance from sample code using CUBLAS:
[Matrix Multiply CUBLAS] - Starting...
GPU Device 0: "GeForce GTX 780M" with compute capability 3.0

iSizeMultiple=8
MatrixA(2048,2048), MatrixB(2048,2048), MatrixC(2048,2048)
Computing result using CUBLAS...done.
Performance= 1211.17 GFlop/s, Time= 14.185 msec, Size= 17179869184 Ops
Computing result using host CPU...done.
Comparing CUBLAS Matrix Multiply with CPU results: PASS

Performance from Fortran call cublas_sgemm:

sugita@sugita-GT70-2OC-2OD:~/fortran-codes/cublas-fortran/testing1$ ./test-cublas-sgemm 
 Matrix A         2048 x        2048
 Matrix B         2048 x        2048
Elapsed time :     0.02400000  secs
Performance:  715.8279   GFLOPS
