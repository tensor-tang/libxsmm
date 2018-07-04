#!/bin/bash
loop=50000

for m in {1..100..4}
do
  for n in {1..100..3}
  do
    for k in {1..100..4}
    do
      echo m,n,k: $m, $n, $k
      echo -e "mkl version \c"; ./mkl_sgemm $m $n $k $loop
      echo -e "smm version \c"; ./xsmm_sgemm $m $n $k $loop
    done
  done
done
