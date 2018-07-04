# make libxsmm
# make CC=gcc WARP=1

SMM_ROOT=/home/tangjian/libxsmm
MKL_ROOT=/home/tangjian/compilers_and_libraries_2018.2.199
# make libxsmm
gcc sgemm.cc -I${SMM_ROOT}/include ${SMM_ROOT}/lib/libxsmm.a ${SMM_ROOT}/lib/libxsmmnoblas.a -ldl -lrt -lpthread -lm -lstdc++ -o sgemm_smm

# make MKL version
gcc sgemm.cc -DMKL -DMKL_DIRECT_CALL_SEQ -I${MKL_ROOT}/include -Wl,--start-group ${MKL_ROOT}/lib/intel64/libmkl_intel_lp64.a ${MKL_ROOT}/lib/intel64/libmkl_core.a ${MKL_ROOT}/lib/intel64/libmkl_sequential.a -Wl,--end-group -ldl -lpthread -lstdc++ -o sgemm_mkl