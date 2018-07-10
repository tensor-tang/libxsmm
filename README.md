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
mkl version     m=1,n=3,k=8 time_us=0.08404
smm version     m=1,n=3,k=8 time_us=0.06474
paddle mkl version m=1,n=3,k=8 time_us=0.14056
paddle smm version m=1,n=3,k=8 time_us=0.07834
m,n,k: 1, 4, 8
mkl version     m=1,n=4,k=8 time_us=0.09978
smm version     m=1,n=4,k=8 time_us=0.08326
paddle mkl version m=1,n=4,k=8 time_us=0.14408
paddle smm version m=1,n=4,k=8 time_us=0.06066
m,n,k: 1, 5, 8
mkl version     m=1,n=5,k=8 time_us=0.11580
smm version     m=1,n=5,k=8 time_us=0.07750
paddle mkl version m=1,n=5,k=8 time_us=0.14900
paddle smm version m=1,n=5,k=8 time_us=0.06800
m,n,k: 8, 3, 8
mkl version     m=8,n=3,k=8 time_us=0.08198
smm version     m=8,n=3,k=8 time_us=0.14804
paddle mkl version m=8,n=3,k=8 time_us=0.20154
paddle smm version m=8,n=3,k=8 time_us=0.17274
m,n,k: 8, 4, 8
mkl version     m=8,n=4,k=8 time_us=0.09304
smm version     m=8,n=4,k=8 time_us=0.15434
paddle mkl version m=8,n=4,k=8 time_us=0.20254
paddle smm version m=8,n=4,k=8 time_us=0.09670
m,n,k: 8, 5, 8
mkl version     m=8,n=5,k=8 time_us=0.10344
smm version     m=8,n=5,k=8 time_us=0.15748
paddle mkl version m=8,n=5,k=8 time_us=0.20432
paddle smm version m=8,n=5,k=8 time_us=0.12690
m,n,k: 8, 3, 151
mkl version     m=8,n=3,k=151 time_us=1.15242
smm version     m=8,n=3,k=151 time_us=0.45062
paddle mkl version m=8,n=3,k=151 time_us=2.84616
paddle smm version m=8,n=3,k=151 time_us=1.90604
m,n,k: 8, 4, 151
mkl version     m=8,n=4,k=151 time_us=1.58536
smm version     m=8,n=4,k=151 time_us=0.65648
paddle mkl version m=8,n=4,k=151 time_us=3.51378
paddle smm version m=8,n=4,k=151 time_us=0.67868
m,n,k: 8, 5, 151
mkl version     m=8,n=5,k=151 time_us=1.91670
smm version     m=8,n=5,k=151 time_us=0.68638
paddle mkl version m=8,n=5,k=151 time_us=4.17288
paddle smm version m=8,n=5,k=151 time_us=1.33254
```
## 5117
```
m,n,k: 1, 3, 8
mkl version     m=1,n=3,k=8 time_us=0.16852
smm version     m=1,n=3,k=8 time_us=0.09506
paddle mkl version m=1,n=3,k=8 time_us=0.15074
paddle smm version m=1,n=3,k=8 time_us=0.08844
m,n,k: 1, 4, 8
mkl version     m=1,n=4,k=8 time_us=0.17230
smm version     m=1,n=4,k=8 time_us=0.13498
paddle mkl version m=1,n=4,k=8 time_us=0.15086
paddle smm version m=1,n=4,k=8 time_us=0.08840
m,n,k: 1, 5, 8
mkl version     m=1,n=5,k=8 time_us=0.20254
smm version     m=1,n=5,k=8 time_us=0.12366
paddle mkl version m=1,n=5,k=8 time_us=0.15060
paddle smm version m=1,n=5,k=8 time_us=0.08802
m,n,k: 8, 3, 8
mkl version     m=8,n=3,k=8 time_us=0.16824
smm version     m=8,n=3,k=8 time_us=0.10422
paddle mkl version m=8,n=3,k=8 time_us=0.33568
paddle smm version m=8,n=3,k=8 time_us=0.14016
m,n,k: 8, 4, 8
mkl version     m=8,n=4,k=8 time_us=0.17936
smm version     m=8,n=4,k=8 time_us=0.13350
paddle mkl version m=8,n=4,k=8 time_us=0.33920
paddle smm version m=8,n=4,k=8 time_us=0.13488
m,n,k: 8, 5, 8
mkl version     m=8,n=5,k=8 time_us=0.20150
smm version     m=8,n=5,k=8 time_us=0.12494
paddle mkl version m=8,n=5,k=8 time_us=0.33732
paddle smm version m=8,n=5,k=8 time_us=0.13544
m,n,k: 8, 3, 151
mkl version     m=8,n=3,k=151 time_us=0.59744
smm version     m=8,n=3,k=151 time_us=0.53470
paddle mkl version m=8,n=3,k=151 time_us=1.16146
paddle smm version m=8,n=3,k=151 time_us=1.06576
m,n,k: 8, 4, 151
mkl version     m=8,n=4,k=151 time_us=0.62466
smm version     m=8,n=4,k=151 time_us=0.68290
paddle mkl version m=8,n=4,k=151 time_us=1.17124
paddle smm version m=8,n=4,k=151 time_us=1.07270
m,n,k: 8, 5, 151
mkl version     m=8,n=5,k=151 time_us=0.71080
smm version     m=8,n=5,k=151 time_us=0.85034
paddle mkl version m=8,n=5,k=151 time_us=1.16638
paddle smm version m=8,n=5,k=151 time_us=1.06204
```

## 6148
```
m,n,k: 1, 3, 8
mkl version     m=1,n=3,k=8 time_us=0.10918
smm version     m=1,n=3,k=8 time_us=0.05880
paddle mkl version m=1,n=3,k=8 time_us=0.09358
paddle smm version m=1,n=3,k=8 time_us=0.05474
m,n,k: 1, 4, 8
mkl version     m=1,n=4,k=8 time_us=0.10560
smm version     m=1,n=4,k=8 time_us=0.07294
paddle mkl version m=1,n=4,k=8 time_us=0.09388
paddle smm version m=1,n=4,k=8 time_us=0.05456
m,n,k: 1, 5, 8
mkl version     m=1,n=5,k=8 time_us=0.12820
smm version     m=1,n=5,k=8 time_us=0.07544
paddle mkl version m=1,n=5,k=8 time_us=0.09396
paddle smm version m=1,n=5,k=8 time_us=0.05470
m,n,k: 8, 3, 8
mkl version     m=8,n=3,k=8 time_us=0.10374
smm version     m=8,n=3,k=8 time_us=0.05876
paddle mkl version m=8,n=3,k=8 time_us=0.21388
paddle smm version m=8,n=3,k=8 time_us=0.08218
m,n,k: 8, 4, 8
mkl version     m=8,n=4,k=8 time_us=0.10518
smm version     m=8,n=4,k=8 time_us=0.07218
paddle mkl version m=8,n=4,k=8 time_us=0.21244
paddle smm version m=8,n=4,k=8 time_us=0.08190
m,n,k: 8, 5, 8
mkl version     m=8,n=5,k=8 time_us=0.12892
smm version     m=8,n=5,k=8 time_us=0.07568
paddle mkl version m=8,n=5,k=8 time_us=0.21594
paddle smm version m=8,n=5,k=8 time_us=0.08230
m,n,k: 8, 3, 151
mkl version     m=8,n=3,k=151 time_us=0.38312
smm version     m=8,n=3,k=151 time_us=0.26616
paddle mkl version m=8,n=3,k=151 time_us=0.63548
paddle smm version m=8,n=3,k=151 time_us=0.43600
m,n,k: 8, 4, 151
mkl version     m=8,n=4,k=151 time_us=0.40000
smm version     m=8,n=4,k=151 time_us=0.31132
paddle mkl version m=8,n=4,k=151 time_us=0.63166
paddle smm version m=8,n=4,k=151 time_us=0.42884
m,n,k: 8, 5, 151
mkl version     m=8,n=5,k=151 time_us=0.40728
smm version     m=8,n=5,k=151 time_us=0.37018
paddle mkl version m=8,n=5,k=151 time_us=0.63324
paddle smm version m=8,n=5,k=151 time_us=0.42970
```
