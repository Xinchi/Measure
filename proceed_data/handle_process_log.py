#!/usr/bin/python

import sys
f = open(sys.argv[1])
lines = f.read().split('\n')

i = 0
t2 = []
t1 = []
for line in lines:
    if (i % 2 == 0):
	try:
	    t1.append(int(line))
	except:
	    break
    else:
	try:
	    t2.append(int(line))
	except:
	    break
    i = i + 1

for i in range(len(t1)):
    print (t1[i] - t2[i])
