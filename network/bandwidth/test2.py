#!/usr/bin/python
from dpkt.ethernet import *
import dpkt.dns
import pcap
from dnslib import DNSRecord
from dnslib import DNSQuestion
from bimap import Bimap
import sys


def add(name,summary_list):
	if name in summary_list:
		summary_list[name] += 1
	else:
		summary_list[name] = 1

def read_file(filename):
	sum_q_length = {}
	sum_q_level = {}
	sum_r_type = {}
	sum_r_class = {}
	sum_r_ttl = {}
	sum_q = {} 
	sum_a = {}
	sum_ns = {}
	sum_ar = {}
	sum_header_qr = {}
	pc = pcap.pcap(filename)
	#pc.setfilter('udp dst port 53')
	count = 0
	for ts,pkt in pc:
		try:
			eth = Ethernet(pkt)
			ip = eth.data
			udp = ip.data
		except:
			continue
		try:
			formatted_data = DNSRecord.parse(udp.data)
		except:
			continue
		id = count
		header = formatted_data.header
		q = header.q
		a = header.a
		ns = header.ns
		ar = header.ar
		
		for i in formatted_data.questions:
			qname = i.qname
			qname_length = len(qname)
			qname_level = len(str(qname).split('.'))
			add(qname_length,sum_q_length)
			add(qname_level,sum_q_level)
		for i in formatted_data.rr:
			add(i.rtype,sum_r_type)
			add(i.rclass,sum_r_class)
			add(i.ttl,sum_r_ttl)

		add(header.qr,sum_header_qr)
		add(q,sum_q)
		add(a,sum_a)
		add(ns,sum_ns)
		add(ar,sum_ar)
		count += 1
#		if (count > 5000):
#			break
	output(sum_header_qr,'header_qr')
	output(sum_q,'q')
	output(sum_a,'a')
	output(sum_ns,'ns')
	output(sum_ar,'ar')
	output(sum_q_length,'q_length')
	output(sum_q_level,'q_level')
	output(sum_r_type,'r_type')
	output(sum_r_class,'r_class')
	output(sum_r_ttl,'r_ttl')
	print 'all_req,',count
	#print '%s,%d,%d,%d,%d,%d'%(sys.argv[1],id,sum_q,sum_a,sum_ns,sum_ar)
def output(summary_list,name):
	for i in summary_list:
		print '%s,%d,%d'%(name,i,summary_list[i])

def main():
	read_file(sys.argv[1])

if __name__ == '__main__':
	main()


