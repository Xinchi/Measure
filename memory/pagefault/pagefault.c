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
    int fdin, fdout;
    //void *src, *dst;
    char* dst;
    struct stat statbuf;
    unsigned long t1, t2;
    long time_sun;
    //fdin = open("./Makefile", O_RDLY);
    //fdout = open("./abc", O_RDWR );
    //fdout = open("./abc", O_RDWR| O_CREAT | O_TRUNC );
    //fdout = open("./abc", O_RDWR);
    //
    //
    //
    //fdout = open("/home/popacai/ram/abc", O_RDONLY);
    fdout = open("./cba", O_RDONLY);

    //lseek(fdout, 1000000 - 1, SEEK_SET);
    //write(fdout,"", 1);


    //dst = mmap(0,statbuf.st_size, PROT_READ | PROT_WRITE,MAP_FILE | MAP_SHARED, fdout, 0);
    //dst = mmap(0, 1000000, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fdout, 0);
    dst = mmap(0, 1000000, PROT_READ, MAP_FILE | MAP_SHARED, fdout, 0);
    char a;
    //memset(dst, 'a', 1000000);
    time_sun = 0;
    int i;
	t1 = get_tsc();
        a = dst[i];
	t2 = get_tsc();
	printf("%ld", t2 - t1);
	/*
    for (i = 0; i < (1000000); i+=100)
    {
	time_sun += t2 - t1;
	printf("%c\n",a);
    }
    //printf("pos=%c\n", dst[0]);
    printf("avg = %f", time_sun *1.0 / 1000);
    */
    close(fdout);
    //memcpy(dst, src, statbuf.st_size);
    exit(0);
}
