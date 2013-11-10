for i in range(1024 * 256 * 2):
    print 'copy(%d);' % (i), 
print
for i in range(1024):
    print 'set(%d);' % (i), 
print
for i in range(1024 / 4):
    print 'copy_int(%d);' % (i), 
print
for i in range(1024 / 4):
    print 'set_int(%d);' % (i), 

