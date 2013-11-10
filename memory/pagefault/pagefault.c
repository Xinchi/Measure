#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}


int main()
{
    int fd;
    unsigned char* dst;
    int size, chunksize;
    //size = 1024 * 1024;
    chunksize = 256 * 1024 * 2;
    size = 1024 * 1024 * 1024 / chunksize;

    fd = open("/home/popacai/ram/ram", O_RDONLY);


    int pos;

    pos = 2;
    dst = mmap(size * pos , size * chunksize, PROT_READ, MAP_SHARED, fd, 0);

    int input;

    int i, j;
    unsigned char tmp[chunksize];	
    unsigned char c;
    unsigned long long sum;
    int flag;
    flag = 0;
    sum = 0;
    long a1, a2;
    a1 = time(0);
    struct timeval t1;
    struct timeval t2;
    int number = 0;
    gettimeofday(&t1, NULL);
    for (i = 0; i < (size * chunksize); i += chunksize)
    {
	//c = dst[i];
	//c = dst[i + 140 * 1024];
	memcpy(tmp, dst+i, chunksize / 2 - 10);
	number++;
    }
    gettimeofday(&t2, NULL);

    long long interval;
    interval = (t2.tv_sec - t1.tv_sec) * 1000000
		+ (t2.tv_usec - t1.tv_usec);
    
    printf("%lf\n", interval * 1.0 / number);
    
    munmap(dst, size* chunksize);
    //msync(dst, size* chunksize, MS_ASYNC);
    //printf("%c\n", *(dst + size* chunksize - 1));
    //printf("%ld\n", (t2 - t1));
    close(fd);
    exit(0);
}
