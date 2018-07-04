#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <omp.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>

#ifdef MKL
#include "mkl.h"
#else 
#include "libxsmm.h"
#endif 

#define FLOAT_TYPE float

#define MKL_MEM_ALIGNMENT 64

int main(int argc, char* argv[])
{
    FLOAT_TYPE* A;
    FLOAT_TYPE* B;
    FLOAT_TYPE* C;
    FLOAT_TYPE  alpha = 1, beta = 0;

    int m = 8;
    int n = 3;
    int k = 151;
    int lda = m;
    int ldb = k;
    int ldc = m;

    int LOOP_COUNT = 20000;
    int i, cores = 1, target = 1, start = 1;
    int fpc = 32;  // default hsw 2.3GHz, FMA enabled. fpc: float operating per cycle
    float hz = 3.5; // default hsw 2.3GHz, FMA enabled. fpc: float operating per cycle

    if (argc == 1) { 
        printf("Usage: %s m n k loop cores hz fpc\n", argv[0]);
        printf("\t hz: CPU frequency in GHz, default=2.3\n");
        printf("\t fpc: float ops per cycle, hsw=32, snb/ivb=16, default=32\n");
    }

    if (argc >= 2) m = atoi(argv[1]);
    if (argc >= 3) n = atoi(argv[2]);
    if (argc >= 4) k = atoi(argv[3]);
    if (argc >= 5) LOOP_COUNT = atoi(argv[4]);
    if (argc >= 6) cores = atoi(argv[5]); 
    if (argc >= 7) hz = (float)atof(argv[6]); 
    if (argc >= 8) fpc = atoi(argv[7]); 

    char transa='N';
    char transb='N';
    lda = m;
    ldb = k;
    ldc = n;

#ifdef MKL
    A = (FLOAT_TYPE*) mkl_malloc(sizeof(FLOAT_TYPE)*lda*k, MKL_MEM_ALIGNMENT);
    B = (FLOAT_TYPE*) mkl_malloc(sizeof(FLOAT_TYPE)*ldb*n, MKL_MEM_ALIGNMENT);
    C = (FLOAT_TYPE*) mkl_malloc(sizeof(FLOAT_TYPE)*ldc*n, MKL_MEM_ALIGNMENT);
#else	
	A = (FLOAT_TYPE*) malloc(sizeof(FLOAT_TYPE)*lda*k);//, MKL_MEM_ALIGNMENT);
    B = (FLOAT_TYPE*) malloc(sizeof(FLOAT_TYPE)*ldb*n);//, MKL_MEM_ALIGNMENT);
    C = (FLOAT_TYPE*) malloc(sizeof(FLOAT_TYPE)*ldc*n); //, MKL_MEM_ALIGNMENT);
#endif

    // random data
	for (i=0; i<lda*k ; ++i) {
	    //	A[i] = (FLOAT_TYPE)rand() / RAND_MAX - 0.5;
        A[i]=i%128;	
        //printf( "Ai = %d, %f \n", i, A[i]);
    }

	for (i=0; i<ldb*n ; ++i) {
        B[i]=i%128;
        //printf( "Bi = %d, %f\n ", i, B[i]);
    	//	B[i] = (FLOAT_TYPE)rand() / RAND_MAX - 0.5;
	}

    /*
	for (i=0; i<ldc*n ; ++i) {
        C[i]=;	//	C[i] = (FLOAT_TYPE)rand() / RAND_MAX - 0.5;
	}*/  

	double gflop = (2.0*m*n*k + 1.0*m*n)*1E-9;

   // for (int c=start; c <= cores; c++) 
   {   // 2699v3 36 cores, 2.3GHz
    /* first call for thread/buffer initialization */


    // omp_set_num_threads(cores); // set thread numbers
    // buring
#ifdef MKL
        sgemm(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc);     
#else
        libxsmm_sgemm(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc);
#endif     

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    for (i=0; i<LOOP_COUNT; ++i) {
#ifdef MKL
        sgemm(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc);
#else
        libxsmm_sgemm(&transa, &transb, &m, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc);
#endif  
    }
	gettimeofday(&end_time,NULL);
    double end_usecs = end_time.tv_usec;
    double end_secs = end_time.tv_sec;

    double start_usecs = start_time.tv_usec;
    double start_secs = start_time.tv_sec;

    double total_time_us = ((end_secs - start_secs)*1000000) + (end_usecs - start_usecs);
    double avg_time_us = total_time_us/(double)LOOP_COUNT;
    double time_avg = avg_time_us/1000000;
       
    printf ("m=%d,n=%d,k=%d cores=%d gflop=%.5f peak=%.5f efficiency=%.5f time_us=%.5f\n",
        m, n, k, cores, gflop / time_avg, (hz * fpc * cores), (gflop / time_avg) / (hz * fpc * cores), avg_time_us);
    }
	//double gflop = (2.0*m*n*k + 1.0*m*n)*1E-9;
/*
	printf("Average time:%e secs \n", time_avg);
	printf("GFlop       :%.5f \n", gflop);
	printf("GFlop/sec   :%.5f \n", gflop/time_avg);
*/
//	printf("C[0] and C[1]: %.3f\t %.3f \n",C[0],C[1]);

#ifdef MKL
	mkl_free(A);
	mkl_free(B);
	mkl_free(C);
#else
	free(A);
	free(B);
	free(C);
#endif

    //shmdt(segptr);
	return 0;
}
