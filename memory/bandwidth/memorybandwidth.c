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

#define DOIT(i) dst[i] = src[i];


void fake_memcpy(int* dst, int* src, int size)
{
    

}

int main()
{
    char** array1;
    char** array2;
    int size, chunk_size;
    int i;
    unsigned long t1, t2;
    size = 500 * 1024;
    chunk_size = 1024;

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
    for (i = size - 100; i < size; i++)
    {
	memcpy(array1[i], array2[i],chunk_size);
    }

    size = size; // Delete the memory in cache


    //start to test
    t1 = get_tsc();
    for (i = 0; i < size; i++)
    {
	memcpy(array2[i], array1[i], chunk_size);
	//fake_memcpy(array2[i], array1[i],chunk_size);
    }
    t2 = get_tsc();
    printf("%f\n", (t2 - t1) * 1.0/ size);

    for (i = 0; i < 500 * 1024; i++)
    {
	free(array2[i]);
	free(array1[i]);
    }
    return 0;
}
