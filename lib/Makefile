CC=gcc
AR=ar
WARNING= -Wall -Wextra
OPTFLAGS= -O0 -march=native
DEBUGFLAGS=

#CFLAGS=
CFLAGS=$(OPTFLAGS) $(WARNINGS)

all: tsc.a tsc.so test_tsc

tsc.a: tsc.c
	$(CC) -c -fPIC -o tsc.o tsc.c $(CFLAGS)
	$(AR) -rc tsc.a tsc.o 
tsc.so: tsc.c
	$(CC) -shared -fPIC tsc.c -o tsc.so $(CFLAGS)

test_tsc: main.c
	$(CC) main.c tsc.a -o test_tsc $(CFLAGS)
test:
	./test_tsc

clean:
	rm *.a
	rm *.so
	rm *.o
	rm test_tsc
