size = 256

for i in range(size):
    item = "*(src++) + "
    print item, 
print

for i in range(size / 4):
    item = "*(((int*)src)++) + " 
    print item, 
print

for i in range(size / 8):
    item = "*(((long*)src)++) + "
    print item, 
print 

for i in range(size):
    item = "*(src++) = 0; "
    print item, 
print

for i in range((size) / 4):
    item = "((((int*)src)++) = 0; "
    print item, 
print

for i in range((size) / 8):
    item = "*(((long*)src)++) = 0; "
    print item, 
print 
