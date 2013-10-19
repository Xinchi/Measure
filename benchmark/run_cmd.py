#!/usr/bin/python
#-*- coding: utf-8 -*-
#By taocai@ucsd.edu

#run_cmd as a subprocess to capture the output of the stdout

from subprocess import *
def run_cmd(cmd):
    cmd_list = cmd.split(' ')
    output = Popen(cmd_list, stdout=PIPE).communicate()[0]
    return output

def output_csv(l):
    for i in l:
	print ',' + i ,
def main():
    print run_cmd("ls /")

if __name__ == '__main__':
    main()
    print 'test_done!'
