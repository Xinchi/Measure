size = 1024

for i in range(size):
    item = "src[%d] & " % i
    print item, 
print

for i in range(size / 8):
    item = "((long*)src)[%d] & " % i
    print item, 
print 
for i in range(size / 4):
    item = "((int*)src)[%d] & " % i
    print item, 

print
for i in range(size + 1):
    item = "src[%d] = " % i
    print item, 
print

for i in range((size + 1) / 8):
    item = "((long*)src)[%d] = " % i
    print item, 
print 
for i in range((size + 1) / 4):
    item = "((int*)src)[%d] = " % i
    print item, 
print
