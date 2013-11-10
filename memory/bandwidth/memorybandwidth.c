#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "bw.h"

#define fake 1
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
    int j;
    for (j = 0; j < (chunk_size / 1024); j++)
    {
	memset_char;
    }
    return 0;
}
int fake_memset_int(char* dst, char* src, int chunk_size)
{
    memset_int;
    return 0;
}
int fake_memcpy_char(char* dst, char* src,int chunk_size)
{
    int j;
    for (j = 0; j < (chunk_size / 1024); j++)
    {
	memcpy_char;
    }
    return 0;
}
int fake_memcpy_int(char* dst, char* src , int chunk_size)
{
    memcpy_int;
    return 0;
}
int main(int argc, char** argv)
{
    char** array1;
    char** array2;
    long long size, chunk_size;
    int i,j ;
    unsigned long t1, t2;
    size = 256 * 1024;
    if (argc == 1)
    {
	chunk_size = 512;
    }else{
	chunk_size = atoi(argv[1]);
	//fprintf(stderr,"chunk_size=%d",chunk_size);
	while ((chunk_size * size) > (512 * 1024 * 1024))
	{
	    size = size / 2;
	}
//	printf("%f\n", size * chunk_size * 1.0 / 1024 / 1024 / 1024);
    }

    array1 = malloc(size * sizeof(char*));
    array2 = malloc(size * sizeof(char*));
    for (i = 0; i < size; i++)
    {
	array1[i] = malloc(chunk_size);
	array2[i] = malloc(chunk_size);
    }


    //after init
    //hot the array1
    for (i = 0; i < size; i++)
    {
	memset(array1[i], 'b', chunk_size);
	memset(array2[i], 'c', chunk_size);
    }
    for (i = size - 10; i < size; i++)
    {
	memcpy(array1[i], array2[i],chunk_size);
    }

    size = size - 10 * 1024; // Delete the memory in cache


    //start to test
    t1 = get_tsc();
    struct timeval n1, n2;
    gettimeofday(&n1);
    for (i = 0; i < size; i++)
    {
	#ifdef cp
	    #ifdef fake
		#ifdef step
		    fake_memcpy_int(array2[i], array1[i],chunk_size);
		#else
		    fake_memcpy_char(array2[i], array1[i],chunk_size);
		#endif
	    #else
		memcpy(array2[i], array1[i], chunk_size);
	    #endif
	#else
	    #ifdef fake
		#ifdef step
		    fake_memset_int(array2[i], 0, chunk_size);
		#else
		    fake_memset_char(array2[i], 0, chunk_size);
		#endif
	    #else
		memset(array2[i], 0, chunk_size);
	    #endif
	#endif
    }
    gettimeofday(&n2);
    t2 = get_tsc();
    //printf("%f", (t2 - t1) * 1.0/ size);
    //printf("%ld", (t2 - t1));
    long interval = 0;
    interval = (n2.tv_sec - n1.tv_sec) * 1000000
		+ (n2.tv_usec - n1.tv_usec);
    //printf("%lf\n", 502.0 * 1000000 / (interval) );
    printf("%lf", (size / 1024 - 10) * chunk_size * 1000000.0 / 1024 / (interval) );

    for (i = 0; i < size + 10; i++)
    {
	free(array2[i]);
	free(array1[i]);
    }
    return 0;
}
