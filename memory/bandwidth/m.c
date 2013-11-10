#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "bw.h"

//#define fake 1
//#define step 1
//#define cp 1
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

int fake_memset_char(char* dst, char* src, int chunk_size)
{
    memset_char;
    return 0;
}
int fake_memset_int(char* dst, char* src, int chunk_size)
{
    memset_int;
    return 0;
}
int fake_memcpy_char(char* dst, char* src,int chunk_size)
{
    memcpy_char;
    return 0;
}
int fake_memcpy_int(char* dst, char* src , int chunk_size)
{
    memcpy_int;
    return 0;
}
int main()
{
    char* array1;
    char* array2;
    char* array3;
    int size, chunk_size;
    int i;
    unsigned long t1, t2;

    chunk_size = 1024 * 1024 * 512; // 512NB 

    

    
    array1 = malloc(chunk_size);
    array2 = malloc(chunk_size);
    array3 = malloc(5 * 1024 * 1024);
    memset(array2,0, chunk_size);
    for (i = 0; i < 10; i++)
    {
	memset(array3, 0, 5 * 1024 * 1024);
    }
    t1 = get_tsc();

    struct timeval n1, n2;
    gettimeofday(&n1);

    memcpy(array1, array2, chunk_size);
    gettimeofday(&n2);
    //t2 = get_tsc();
    long interval = 0;
    interval = (n2.tv_sec - n1.tv_sec) * 1000000
		+ (n2.tv_usec - n1.tv_usec);
    printf("%lf\n", 512.0 * 1000000 / (interval) );
    //printf("%ld", (n2 - n1));
    free(array3);
    free(array2);
    free(array1);
    return 0;
}
