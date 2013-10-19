CC=gcc
AR=ar
WARNING= -Wall -Wextra
OPTFLAGS= -O0 -march=native
DEBUGFLAGS=

#CFLAGS=
CFLAGS=$(OPTFLAGS) $(WARNINGS)

all: benchmark

benchmark: benchmark.c
	$(CC) $< -o benchmark $(CFLAGS)
test:
	./benchmark ls 

clean:
	rm benchmark
