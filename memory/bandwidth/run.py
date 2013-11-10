#!/usr/bin/python
import sys
import os


def set_flag(context ,message, value):
    m = ("#define %s 1" % message)
    nm = "//" + m

    nm = "\n" + nm
    m = "\n" + m
    if value:
	context = context.replace(nm, m)
    else:
	context = context.replace(m, nm)
    return context

original_path = os.getcwd()
current_path = os.path.realpath(__file__).replace("run.py", "")
os.chdir(current_path)
if (len(sys.argv) < 2):
    print '[bandwidth] run.py, memcpy/memset/charset/charcpy/intset/intcpy/longcpy/longset'
    exit();

f = open(current_path + "memorybandwidth.c", "r")
context = f.read()
f.close()

command = sys.argv[1]
if (command == 'memcpy'):
    context = set_flag(context, "fake", False)
    context = set_flag(context, "step", False)
    context = set_flag(context, "cp", True)

if (command == 'memset'):
    context = set_flag(context, "fake", False)
    context = set_flag(context, "step", False)
    context = set_flag(context, "cp", False)

if (command == 'charset'):
    context = set_flag(context, "fake", True)
    context = set_flag(context, "step", False)
    context = set_flag(context, "cp", False)

if (command == 'charcpy'):
    context = set_flag(context, "fake", True)
    context = set_flag(context, "step", False)
    context = set_flag(context, "cp", True)

if (command == 'intset'):
    context = set_flag(context, "fake", True)
    context = set_flag(context, "step", True)
    context = set_flag(context, "cp", False)

if (command == 'intcpy'):
    context = set_flag(context, "fake", True)
    context = set_flag(context, "step", True)
    context = set_flag(context, "cp", True)
if (command == 'longcpy'):
    os.system("./m")
    os.chdir(original_path)
    exit()

if (command == 'longset'):
    os.system("./n")
    os.chdir(original_path)
    exit()

f = open("memorybandwidth.c", "w")
f.write(context)
f.close()

os.system("make")
try:
    os.system("./memorybandwidth " + sys.argv[2])
except:
    os.system("./memorybandwidth")

os.chdir(original_path)
