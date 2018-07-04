#include <stdio.h>  // for printf
#include <assert.h>
#include <stdlib.h>  // for malloc and free
#include <sys/time.h>
#ifdef MKL
#include "mkl.h"
#else
#include "libxsmm.h"
#endif

// or 64
#define MEM_ALIGNMENT 4096

int main(int argc, char* argv[]) {
  void* A;
  void* B;
  void* C;
  float alpha = 1, beta = 0;

  int m = 8;
  int n = 3;
  int k = 151;

  int LOOP_COUNT = 20000;

  if (argc == 1) {
    printf("Usage: %s m n k loop\n", argv[0]);
  }

  if (argc >= 2) m = atoi(argv[1]);
  if (argc >= 3) n = atoi(argv[2]);
  if (argc >= 4) k = atoi(argv[3]);
  if (argc >= 5) LOOP_COUNT = atoi(argv[4]);

  // malloc data
  assert(posix_memalign(&A, MEM_ALIGNMENT, sizeof(float) * m * k) == 0);
  assert(posix_memalign(&B, MEM_ALIGNMENT, sizeof(float) * k * n) == 0);
  assert(posix_memalign(&C, MEM_ALIGNMENT, sizeof(float) * m * n) == 0);

  // random data
  for (int i = 0; i < m * k; ++i) {
    float* a = (float*)A;
    a[i] = i % 128;
  }
  for (int i = 0; i < k * n; ++i) {
    float* b = (float*)B;
    b[i] = i % 128;
  }

  struct timeval start_time, end_time;
#ifdef MKL
  bool transA = false;
  bool transB = false;
  int lda = transA == false ? k : m;
  int ldb = transB == false ? n : k;
  int ldc = n;
  // buring time
  cblas_sgemm(CblasRowMajor,
              transA == false ? CblasNoTrans : CblasTrans,
              transB == false ? CblasNoTrans : CblasTrans,
              m,
              n,
              k,
              alpha,
              (float*)A,
              lda,
              (float*)B,
              ldb,
              beta,
              (float*)C,
              ldc);

  gettimeofday(&start_time, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i) {
    cblas_sgemm(CblasRowMajor,
                transA == false ? CblasNoTrans : CblasTrans,
                transB == false ? CblasNoTrans : CblasTrans,
                m,
                n,
                k,
                alpha,
                (float*)A,
                lda,
                (float*)B,
                ldb,
                beta,
                (float*)C,
                ldc);
  }
  gettimeofday(&end_time, NULL);
#else
  // Colmajor
  char transa = 'N';
  char transb = 'N';
  int lda = m;
  int ldb = k;
  int ldc = m;
  libxsmm_sgemm(
      &transa, &transb, &m, &n, &k, &alpha, (float*)A, &lda, (float*)B, &ldb, &beta, (float*)C, &ldc);

  gettimeofday(&start_time, NULL);
  for (int i = 0; i < LOOP_COUNT; ++i) {
    libxsmm_sgemm(
        &transa, &transb, &m, &n, &k, &alpha, (float*)A, &lda, (float*)B, &ldb, &beta, (float*)C, &ldc);
  }
  gettimeofday(&end_time, NULL);
#endif

  double end_usecs = end_time.tv_usec;
  double end_secs = end_time.tv_sec;

  double start_usecs = start_time.tv_usec;
  double start_secs = start_time.tv_sec;

  double total_time_us =
      ((end_secs - start_secs) * 1000000) + (end_usecs - start_usecs);
  double avg_time_us = total_time_us / (double)LOOP_COUNT;

  printf("m=%d,n=%d,k=%d time_us=%.5f\n", m, n, k, avg_time_us);

  free(A);
  free(B);
  free(C);

  return 0;
}
