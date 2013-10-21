#!/usr/bin/python

import sys
f = open(sys.argv[1])
lines = f.read().split('\n')

value1 = 0
value2 = 0
for line in lines:
    value2 = int(line)
    print value2 - value1
    value1 = value2

