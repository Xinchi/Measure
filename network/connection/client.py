#!/usr/bin/python
#-*- coding: utf-8 -*-

'''
    Network bandwidth measurement tools
    By taocai@ucsd.edu
'''

import socket
from threading import Thread
import time
import os
import sys

def main():
    addr = sys.argv[1]
    port = int(sys.argv[2])
    for i in range(100):
	print addr, port
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((addr, port));
	time.sleep(0.5)
	s.close()
	time.sleep(1)
	port = port + 1

if __name__ == '__main__':
    main()


