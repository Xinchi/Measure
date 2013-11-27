#!/usr/bin/python
from dpkt.ethernet import *
import pcap
import sys


def add(name,summary_list):
	if name in summary_list:
		summary_list[name] += 1
	else:
		summary_list[name] = 1

def read_file(filename):
    pc = pcap.pcap(filename)
    count = 0
    for ts,pkt in pc:
	try:
	    print ts
	except:
	    print 'exception'
def main():
    read_file(sys.argv[1])
if __name__ == '__main__':
	main()


