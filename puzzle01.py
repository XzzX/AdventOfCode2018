#!/usr/bin/python

import numpy as np

data = np.loadtxt("input01.txt", dtype = int)
print(data.sum())

freqs = set()
cf    = 0
for i in range(500):
    for v in data:
        cf += v
        if cf in freqs:
            print(cf)
            break
        else:
            freqs = freqs | {cf}

#print(freqs)
