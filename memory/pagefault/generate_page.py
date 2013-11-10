#!/usr/bin/python

import os
os.unlink("ram");
s = 'a' * 1024 * 1024

f = open('ram','w')
for i in range(1024):
    f.write(s)

f.close()
