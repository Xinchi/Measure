#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "bw.h"

unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}


int main()
{
    int fd;
    unsigned long t1, t2;
    unsigned char* dst;
    int size, chunksize;
    size = 1024 * 1024;
    chunksize = 1024;
    fd = open("/home/popacai/ram/ram", O_RDONLY);


    int pos;

    pos = 0;
    dst = mmap(size * pos , size * chunksize , PROT_READ, MAP_SHARED, fd, 0);


    int i, j;
    unsigned char tmp[1024];	
    unsigned char c;
    t1 = get_tsc();
    for (i = 0; i < (size * chunksize); i += chunksize)
    {
	//memcpy(tmp, dst+i, chunksize);
	//memcpy_char;
	c = dst[i];
    }
    t2 = get_tsc();
    munmap(dst, size* chunksize);
    //msync(dst, size* chunksize, MS_ASYNC);
    //printf("%c\n", *(dst + size* chunksize - 1));
    //printf("%ld\n", (t2 - t1));
    printf("%ld\n", (t2 - t1) / size);
    close(fd);
    exit(0);
}
