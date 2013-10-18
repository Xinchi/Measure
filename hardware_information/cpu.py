#!/usr/bin/python
#-*- coding: utf-8 -*-
#By taocai@ucsd.edu
#Publish in GPLv2

'''demand:
    Processor: model, cycle time, cache sizes (L1, L2, instruction, data, etc.)
'''

import run_cmd
import os
def get_cache(cmd = '/sys/devices/system/cpu/'):
    output = run_cmd.run_cmd("ls " + cmd).split('\n')
    path = []
    for item in output:
	if item.startswith('cpu'):
	    path.append('/'.join([cmd,item,'cache/']))
    index_path = []
    for i in path:
	if os.path.exists(i):
	    output = run_cmd.run_cmd("ls " + i).split('\n')
	    for j in output:
		index_path.append('/'.join([i,j]))
    cat_cmd = []
    for i in index_path:
	path = '/'.join([i,'size'])
	if os.path.exists(path):
	    cat_cmd.append( "cat " + path)
    output = []
    for i in cat_cmd:
	output.append(i + "," + run_cmd.run_cmd(i).strip())
    
    trim_output = []
    for i in output:
	trim_output.append(i.replace(cmd,'').replace('cache/','').replace('cat ',''))
    return trim_output
def output_cache(cache_info):
    for i in cache_info:
	print i


def get_cpuinfo(cmd = "cat /proc/cpuinfo"):
    output = run_cmd.run_cmd(cmd).split('\n')
    cpuinfo = {}
    for line in output:
	tmp = line.split(':')
	if (len(tmp) < 2 or len(tmp) > 2):
	    continue
    	key = tmp[0].strip()
	value = tmp[1].strip()
	if key in cpuinfo:
	    cpuinfo[key].append(value)
	else:
	    cpuinfo[key] = [value]
    return cpuinfo

def output_cpuinfo(cpuinfo):
    key_list = ['processor',\
		'model name',\
		'cpu MHz',\
		'flags',\
		'address sizes',\
		]
    for key in key_list:
	print key,
	run_cmd.output_csv(cpuinfo[key])
	print
   
def get_model(core = 0):
    pass

def main():
    
    output_cpuinfo(get_cpuinfo())
    output_cache(get_cache())

if __name__ == '__main__':
    main()
