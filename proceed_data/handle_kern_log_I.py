#/usr/bin/python

import sys
def main():
    f = open(sys.argv[1]) # read log
    raw_data = f.read() 
    lines = raw_data.split('\n')

    captured_data = []
    for line in lines:
	index = line.find('TAOI:')
	if (index != -1):
	    captured_data.append(line[index:])
	else:
	    continue

    for line in captured_data:
	data = line.split(':')
	key = data[1]
	value = data[2].split('=')[1]
	print value
	#print key,value

if __name__ == '__main__':
    main()
