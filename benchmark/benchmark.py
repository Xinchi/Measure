#/usr/bin/python

import run_cmd
import sys
def test_once(cmd):
    print run_cmd.run_cmd(cmd)

def test_loop(cmd, loop):
    for i in range(loop):
	print run_cmd.run_cmd(cmd)

if __name__ == '__main__':
    test_loop(sys.argv[1], 1000)

