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

//#define STEP 8
int fake_memset_char(char* dst, char* src, int chunk_size)
{
    int i;
    /*
    for (i = 0; i < chunk_size / STEP; i++)
    {
	*(dst++) = *(src++);
    }
    */
#ifdef step 
    for (i = 0; i < (chunk_size / 8); i++)
    {
	//*((long*)dst++) = *((long*)src++);
	*((long*)dst++) = 0;
	//*(((long*)dst)++) = *(((long*)src)++);
    }
#else
    for (i = 0; i < (chunk_size); i++)
    {
	*(dst++) = 0;
	//*((long*)dst++) = 0;
	//*(((long*)dst)++) = *(((long*)src)++);
    }

#endif
    return 0;
}
int fake_memset_int(char* dst, char* src, int chunk_size)
{
    //memset_int;
    return 0;
}
int fake_memcpy_char(char* dst, char* src,int chunk_size)
{
    int i;
#ifdef step 
    for (i = 0; i < (chunk_size / 8); i++)
    {
	*((long*)dst++) = *((long*)src++);
    }
#else
    for (i = 0; i < (chunk_size); i++)
    {
	*(dst++) = *(src++);
	//*((long*)dst++) = 0;
	//*(((long*)dst)++) = *(((long*)src)++);
    }
#endif

    return 0;
}
int fake_memcpy_int(char* dst, char* src , int chunk_size)
{
    //memcpy_int;
    return 0;
}
int main(int argc, char** argv)
{
    char** array1;
    long long size, chunk_size;
    int i,j ;
    unsigned long t1, t2;
    size = 256 * 1024;
    if (argc == 1)
    {
	chunk_size = 1024;
    }else{
	chunk_size = atoi(argv[1]);
	//fprintf(stderr,"chunk_size=%d",chunk_size);
	while ((chunk_size * size) >= (1024 * 1024 * 1024))
	{
	    size = size / 2;
	}
//	printf("%f\n", size * chunk_size * 1.0 / 1024 / 1024 / 1024);
    }

    char* all1, all2;
    char* array2;

    all1 = malloc(size * chunk_size);
    array1 = malloc(size * sizeof(char*));
    array2 = malloc(chunk_size);
    
    for (i = 0; i < size; i++)
    {
	//array1[i] = malloc(chunk_size);
	//array2[i] = malloc(chunk_size);
	array1[i] = all1 + chunk_size * i;
	//array2[i] = all2 + chunk_size * i;
    }
    for (i = 0; i < size; i++)
    {
	memset(array1[i], 'b', chunk_size);
    }
    for (i = 0; i < 1024; i++)
    {
	memset(array2, 0, chunk_size);
    }

    /*
    //after init
    //hot the array1
    for (j = 0; j < 1024; j++)
    {
	//memset(all1 + (size - 10 * 1024) * chunk_size, 0, chunk_size * 10 * 1024);
	for (i = size - 10 * 1024; i < size; i++)
	{
	    memset(array1[i], 0, chunk_size);
	}
    }
    */
    
    //size = size - 10 * 1024; // Delete the memory in cache


    //start to test
    t1 = get_tsc();
    int x;
    struct timeval n1, n2;
    long long interval;
    for (x = 0; x < 100; x++)
    {
	gettimeofday(&n1);
	for (i = 0; i < size; i++)
	{
	    #ifdef cp
		#ifdef fake
			fake_memcpy_char(array2, array1[i],chunk_size);
		#else
		    memcpy(array2, array1[i], chunk_size);
		#endif
	    #else
		#ifdef fake
			fake_memset_char(array1[i], 0, chunk_size);
		#else
		    memset(array1[i], 0, chunk_size);
		#endif
	    #endif
	}
	gettimeofday(&n2);
	interval = 0;
	interval = (unsigned long long)(n2.tv_sec - n1.tv_sec) * 1000000
		    + (n2.tv_usec - n1.tv_usec);
	//printf("%lf\n", 502.0 * 1000000 / (interval) );
	long long overhead = 0;
	#ifdef fake
	    overhead = 67 * chunk_size * size;
	    overhead = overhead / 1024 / 1024 / 2530;
            #ifdef step
		overhead = overhead / 8;
	    #endif
	#endif
	printf("%d, %lf, %d\n", x, 1.0 * (size) * chunk_size * 1000000.0 / 1024 / 1024 / (interval - overhead), chunk_size * size);
	fprintf(stderr,"%d, %lf\n", x, 1.0 * (size) * chunk_size * 1000000.0 / 1024 / 1024 / (interval));
    }

    //printf("%f", (t2 - t1) * 1.0/ size);
    //printf("%ld", (t2 - t1));
   
    for (i = 0; i < size + 10; i++)
    {
//	free(array2[i]);
//	free(array1[i]);

    }
    //free(array1);
    //free(array2);
    //free(all1);
    return 0;
}
