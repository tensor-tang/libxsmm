# libxsmm
Some tests about libxsmm

# compile
change the root path of libxsmm and mkl in make.sh.

Then run make.sh

# benchmark
run benchmark.sh

mkl_sgemm is faster than paddle_mkl_sgemm, becasue mkl_sgemm use direct call and use mkl_malloc outside the sgemm.

While paddle_xsmm_sgemm and xsmm_sgemm should have same speed.
