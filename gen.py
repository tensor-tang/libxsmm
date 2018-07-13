from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

import sys
import re

filename = "res.txt.2620"
if len(sys.argv) > 1:
    filename = sys.argv[1]

print "filename", filename

res = dict()
# k,m,n
res['mkl']=np.zeros((200, 200, 200))
res['smm']=np.zeros((200, 200, 200))

pattern_mkl = re.compile(r'.*paddle mkl version m=(.*),n=(.*),k=(.*) time_us=(.*).*')
pattern_smm = re.compile(r'.*paddle smm version m=(.*),n=(.*),k=(.*) time_us=(.*).*')

maxk = 0
with open(filename) as f:
    for line in f:
        match_mkl = re.match(pattern_mkl, line)
        match_smm = re.match(pattern_smm, line)
        if match_mkl:
            if match_mkl.group(4) is None:
                continue
            assert match_mkl.group(4) != '0'
            #print match_mkl.groups()
            m = int(match_mkl.group(1)) -1
            n = int(match_mkl.group(2)) -1
            k = int(match_mkl.group(3)) -1
            us = float(match_mkl.group(4))
            res['mkl'][k][m][n] = us
            maxk = k if k > maxk else maxk
        if match_smm:
            if match_smm.group(4) is None:
                continue
            assert match_smm.group(4) != '0'
            #print match_smm.groups()
            m = int(match_smm.group(1)) -1
            n = int(match_smm.group(2)) -1
            k = int(match_smm.group(3)) -1
            us = float(match_smm.group(4))
            res['smm'][k][m][n] = us
            maxk = k if k > maxk else maxk

#print res['smm'][0]
#print res['mkl'][0]

for k in range(maxk):
    res_k = res['mkl'][k] / res['smm'][k] - 1.0
    print "K[m=0]:", k
    print res_k[0]

    fig = plt.figure(k)
    ax = Axes3D(fig)
    X = np.arange(1, 201)
    Y = np.arange(1, 201)
    X, Y = np.meshgrid(X, Y)
    Z = res['mkl'][0] / res['smm'][0] - 1.0
     
    ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='rainbow')
    
    plt.show()
