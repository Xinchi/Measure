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
    port = sys.argv[2]
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((addr, port));
    s.close()
if __name__ == '__main__':
    main()


