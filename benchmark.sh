#!/bin/bash
loop=50000
function compare() {
  m=$1
  n=$2
  k=$3
#  echo m,n,k: $m, $n, $k
#  echo -e "mkl version \t\c"; ./mkl_sgemm $m $n $k $loop
#  echo -e "smm version \t\c"; ./xsmm_sgemm $m $n $k $loop
  echo -e "paddle mkl version \c"; ./paddle_mkl_sgemm $m $n $k $loop
  echo -e "paddle smm version \c"; ./paddle_xsmm_sgemm $m $n $k $loop
}

# test cases
compare 1 3 8
compare 1 4 8
compare 1 5 8

compare 8 3 8
compare 8 4 8
compare 8 5 8

compare 8 3 151
compare 8 4 151
compare 8 5 151

# skip below test
# exit 0

for k in {1..200..1}
do
  for m in {1..200}
  do
    for n in {1..200..1}
    do
      compare $m $n $k
    done
  done
done
