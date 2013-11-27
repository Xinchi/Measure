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


global huge_message
huge_message = 'a' * 8196
class GTTimer(Thread):
    def __init__(self, vector, wait_time):
	Thread.__init__(self)
	self.vector = vector
	self.wait_time = wait_time
	self.vector[0] = 0
	self.vector[1] = 0
    def reset(self):
	self.vector[0] = 0
	self.vector[1] = 0
    def run(self):
	time.sleep(1)
	self.reset()

class GTSocket(Thread):
    def __init__(self, connection, action, vector):
	Thread.__init__(self)
	self.connection = connection
	self.action = action
	self.vector = vector
    def run(self):
	if self.action == 'recv':
	    while True:
	        message = self.connection.recv(8196)
		self.vector[1] += len(message)
	if self.action == 'send':
	    while (True):
		self.vector[1] += self.connection.send(huge_message)
    

def make_connection(addr, types):
    if (types == 'TCP'):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(addr);
    if (types == 'UDP'):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    return s

def make_listen(addr, types):
    if (types == 'TCP'):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if (types == 'UDP'):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind(addr)
    return s
    
def main():
    if (len(sys.argv) < 6):
	print 'usage: GTbw.py address port types[TCP/UDP] action[send/recv] parallel, time'
	exit()
    addr = sys.argv[1]
    port = int(sys.argv[2])
    types = sys.argv[3] 
    action = sys.argv[4]
    Nparallel = int(sys.argv[5])
    
    vector = [0, 0]
    t = GTTimer(vector, 10)
    t.setDaemon(True)
    if (action == 'recv'):
	s = make_listen((addr, port), types)
	s.listen(20)
	while (True):
	    conn, addr = s.accept()
	    print addr
	    g = GTSocket(conn, 'recv', vector)
	    g.setDaemon(True)
	    g.start()

    if (action == 'send'): 
	for i in range(Nparallel):
	    conn = make_connection((addr, port), types)
	    g = GTSocket(conn, 'send', vector)
	    g.setDaemon(True)
	    g.start()
	t.start()
	time.sleep(5)
	print vector
	print vector[1] * 1.0 / 1024 /1024 / 5
	    
def test():
    s = make_connection(('127.0.0.1',80), 'TCP')

    g = GTSocket(s, 'send', [])
    g.setDaemon(True)
    g.start()
    time.sleep(1)

if __name__ == '__main__':
    main()


