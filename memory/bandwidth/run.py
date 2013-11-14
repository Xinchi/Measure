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
    print '[bandwidth] run.py, char/int/long.read/write'
    exit();

f = open(current_path + "memorybandwidth.c", "r")
context = f.read()
f.close()

command = sys.argv[1]
if (command == 'charread'):
    context = set_flag(context, "read", True)
    context = set_flag(context, "write", False)
    context = set_flag(context, "char_step", True)
    context = set_flag(context, "int_step", False)
    context = set_flag(context, "long_step", False)
if (command == 'intread'):
    context = set_flag(context, "read", True)
    context = set_flag(context, "write", False)
    context = set_flag(context, "char_step", False)
    context = set_flag(context, "int_step", True)
    context = set_flag(context, "long_step", False)
if (command == 'longread'):
    context = set_flag(context, "read", True)
    context = set_flag(context, "write", False)
    context = set_flag(context, "char_step", False)
    context = set_flag(context, "int_step", False)
    context = set_flag(context, "long_step", True)

if (command == 'charwrite'):
    context = set_flag(context, "read", False)
    context = set_flag(context, "write", True)
    context = set_flag(context, "char_step", True)
    context = set_flag(context, "int_step", False)
    context = set_flag(context, "long_step", False)


if (command == 'intwrite'):
    context = set_flag(context, "read", False)
    context = set_flag(context, "write", True)
    context = set_flag(context, "char_step", False)
    context = set_flag(context, "int_step", True)
    context = set_flag(context, "long_step", False)

if (command == 'longwrite'):
    context = set_flag(context, "read", False)
    context = set_flag(context, "write", True)
    context = set_flag(context, "char_step", False)
    context = set_flag(context, "int_step", False)
    context = set_flag(context, "long_step", True)
f = open("memorybandwidth.c", "w")
f.write(context)
f.close()

os.system("make")
try:
    os.system("./memorybandwidth " + sys.argv[2])
except:
    os.system("./memorybandwidth")

os.chdir(original_path)
