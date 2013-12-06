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
    port = int(sys.argv[1])
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.listen(('0.0.0.0', port));
    addr, conn = s.accept()
    print addr
if __name__ == '__main__':
    main()


