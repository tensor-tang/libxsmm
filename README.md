# libxsmm
Some tests about libxsmm

# compile
change the root path of libxsmm and mkl in make.sh.

Then run make.sh

# benchmark
run benchmark.sh

mkl_sgemm is faster than paddle_mkl_sgemm, becasue mkl_sgemm use direct call and use mkl_malloc outside the sgemm.

While paddle_xsmm_sgemm and xsmm_sgemm should have same speed.

## 2620 v2
```
m,n,k: 1, 3, 8
mkl version     m=1,n=3,k=8 time_us=0.08332
smm version     m=1,n=3,k=8 time_us=0.07314
paddle mkl version m=1,n=3,k=8 time_us=0.14104
paddle smm version m=1,n=3,k=8 time_us=0.06486
m,n,k: 1, 4, 8
mkl version     m=1,n=4,k=8 time_us=0.09976
smm version     m=1,n=4,k=8 time_us=0.07430
paddle mkl version m=1,n=4,k=8 time_us=0.14496
paddle smm version m=1,n=4,k=8 time_us=0.08014
m,n,k: 1, 5, 8
mkl version     m=1,n=5,k=8 time_us=0.11566
smm version     m=1,n=5,k=8 time_us=0.07962
paddle mkl version m=1,n=5,k=8 time_us=0.15126
paddle smm version m=1,n=5,k=8 time_us=0.08014
m,n,k: 8, 3, 8
mkl version     m=8,n=3,k=8 time_us=0.08046
smm version     m=8,n=3,k=8 time_us=0.15250
paddle mkl version m=8,n=3,k=8 time_us=0.20144
paddle smm version m=8,n=3,k=8 time_us=0.14802
m,n,k: 8, 4, 8
mkl version     m=8,n=4,k=8 time_us=0.08716
smm version     m=8,n=4,k=8 time_us=0.15472
paddle mkl version m=8,n=4,k=8 time_us=0.20394
paddle smm version m=8,n=4,k=8 time_us=0.16290
m,n,k: 8, 5, 8
mkl version     m=8,n=5,k=8 time_us=0.10366
smm version     m=8,n=5,k=8 time_us=0.16036
paddle mkl version m=8,n=5,k=8 time_us=0.20550
paddle smm version m=8,n=5,k=8 time_us=0.16406
m,n,k: 8, 3, 151
mkl version     m=8,n=3,k=151 time_us=1.16692
smm version     m=8,n=3,k=151 time_us=0.44998
paddle mkl version m=8,n=3,k=151 time_us=2.87770
paddle smm version m=8,n=3,k=151 time_us=0.43492
m,n,k: 8, 4, 151
mkl version     m=8,n=4,k=151 time_us=1.59640
smm version     m=8,n=4,k=151 time_us=0.65572
paddle mkl version m=8,n=4,k=151 time_us=3.53822
paddle smm version m=8,n=4,k=151 time_us=0.63052
m,n,k: 8, 5, 151
mkl version     m=8,n=5,k=151 time_us=1.91988
smm version     m=8,n=5,k=151 time_us=0.68806
paddle mkl version m=8,n=5,k=151 time_us=4.18634
paddle smm version m=8,n=5,k=151 time_us=0.66490
```
## 5117
```
m,n,k: 1, 3, 8
mkl version     m=1,n=3,k=8 time_us=0.16850
smm version     m=1,n=3,k=8 time_us=0.09784
paddle mkl version m=1,n=3,k=8 time_us=0.16484
paddle smm version m=1,n=3,k=8 time_us=0.09560
m,n,k: 1, 4, 8
mkl version     m=1,n=4,k=8 time_us=0.17240
smm version     m=1,n=4,k=8 time_us=0.11450
paddle mkl version m=1,n=4,k=8 time_us=0.15086
paddle smm version m=1,n=4,k=8 time_us=0.11494
m,n,k: 1, 5, 8
mkl version     m=1,n=5,k=8 time_us=0.20254
smm version     m=1,n=5,k=8 time_us=0.12356
paddle mkl version m=1,n=5,k=8 time_us=0.15070
paddle smm version m=1,n=5,k=8 time_us=0.12360
m,n,k: 8, 3, 8
mkl version     m=8,n=3,k=8 time_us=0.16982
smm version     m=8,n=3,k=8 time_us=0.09556
paddle mkl version m=8,n=3,k=8 time_us=0.33568
paddle smm version m=8,n=3,k=8 time_us=0.10226
m,n,k: 8, 4, 8
mkl version     m=8,n=4,k=8 time_us=0.17192
smm version     m=8,n=4,k=8 time_us=0.11474
paddle mkl version m=8,n=4,k=8 time_us=0.33828
paddle smm version m=8,n=4,k=8 time_us=0.11456
m,n,k: 8, 5, 8
mkl version     m=8,n=5,k=8 time_us=0.20158
smm version     m=8,n=5,k=8 time_us=0.12298
paddle mkl version m=8,n=5,k=8 time_us=0.33918
paddle smm version m=8,n=5,k=8 time_us=0.12936
m,n,k: 8, 3, 151
mkl version     m=8,n=3,k=151 time_us=0.59892
smm version     m=8,n=3,k=151 time_us=0.55392
paddle mkl version m=8,n=3,k=151 time_us=1.16742
paddle smm version m=8,n=3,k=151 time_us=0.53352
m,n,k: 8, 4, 151
mkl version     m=8,n=4,k=151 time_us=0.62502
smm version     m=8,n=4,k=151 time_us=0.68166
paddle mkl version m=8,n=4,k=151 time_us=1.16856
paddle smm version m=8,n=4,k=151 time_us=0.67956
m,n,k: 8, 5, 151
mkl version     m=8,n=5,k=151 time_us=0.71098
smm version     m=8,n=5,k=151 time_us=0.85376
paddle mkl version m=8,n=5,k=151 time_us=1.16668
paddle smm version m=8,n=5,k=151 time_us=0.83334
```
##6148
```
m,n,k: 1, 3, 8
mkl version     m=1,n=3,k=8 time_us=0.10482
smm version     m=1,n=3,k=8 time_us=0.05922
paddle mkl version m=1,n=3,k=8 time_us=0.09414
paddle smm version m=1,n=3,k=8 time_us=0.05940
m,n,k: 1, 4, 8
mkl version     m=1,n=4,k=8 time_us=0.10678
smm version     m=1,n=4,k=8 time_us=0.07328
paddle mkl version m=1,n=4,k=8 time_us=0.09466
paddle smm version m=1,n=4,k=8 time_us=0.07914
m,n,k: 1, 5, 8
mkl version     m=1,n=5,k=8 time_us=0.13632
smm version     m=1,n=5,k=8 time_us=0.07572
paddle mkl version m=1,n=5,k=8 time_us=0.09458
paddle smm version m=1,n=5,k=8 time_us=0.07648
m,n,k: 8, 3, 8
mkl version     m=8,n=3,k=8 time_us=0.10426
smm version     m=8,n=3,k=8 time_us=0.06168
paddle mkl version m=8,n=3,k=8 time_us=0.21420
paddle smm version m=8,n=3,k=8 time_us=0.05986
m,n,k: 8, 4, 8
mkl version     m=8,n=4,k=8 time_us=0.10652
smm version     m=8,n=4,k=8 time_us=0.07262
paddle mkl version m=8,n=4,k=8 time_us=0.21476
paddle smm version m=8,n=4,k=8 time_us=0.07352
m,n,k: 8, 5, 8
mkl version     m=8,n=5,k=8 time_us=0.12938
smm version     m=8,n=5,k=8 time_us=0.07586
paddle mkl version m=8,n=5,k=8 time_us=0.21882
paddle smm version m=8,n=5,k=8 time_us=0.07618
m,n,k: 8, 3, 151
mkl version     m=8,n=3,k=151 time_us=0.38552
smm version     m=8,n=3,k=151 time_us=0.26162
paddle mkl version m=8,n=3,k=151 time_us=0.63364
paddle smm version m=8,n=3,k=151 time_us=0.25790
m,n,k: 8, 4, 151
mkl version     m=8,n=4,k=151 time_us=0.39960
smm version     m=8,n=4,k=151 time_us=0.31272
paddle mkl version m=8,n=4,k=151 time_us=0.63292
paddle smm version m=8,n=4,k=151 time_us=0.31126
m,n,k: 8, 5, 151
mkl version     m=8,n=5,k=151 time_us=0.41126
smm version     m=8,n=5,k=151 time_us=0.37858
paddle mkl version m=8,n=5,k=151 time_us=0.63520
paddle smm version m=8,n=5,k=151 time_us=0.35946
```
