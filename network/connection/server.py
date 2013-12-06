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

    for i in range(100):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind(('0.0.0.0', port))
	s.listen(5);
	conn, addr = s.accept()
	#conn.close()
	print addr
	time.sleep(0.5)
	s.close()
	port = port + 1
if __name__ == '__main__':
    main()


