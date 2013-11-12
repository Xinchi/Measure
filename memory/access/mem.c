#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "math.h"
#include <stdlib.h>
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

unsigned long diff_tsc(unsigned long t1, unsigned long t2)
{
    return (t2 - t1 - 67);
}

#define TIMES 320
#define STRIDE 1096
#define HOT_SIZE 3172
#define TARGET_SIZE 320//kb

int test()
{
	unsigned long t1;
	unsigned long t2;
	double diff;

	//we put 20k in l2 size, and fill the l1 with all 8kb
	int* l1; 
	int* discontinue; 
	int* l2;
	int stride = STRIDE/4; //stride size = 1024.  
	int array_size = TARGET_SIZE*1024/4;
	l1 = malloc(1024*HOT_SIZE);
	discontinue = malloc(1024*1024*3);
	l2 = malloc(1024*TARGET_SIZE);

	int i;
	for(i=0;i<HOT_SIZE*1024/4;i++)
	{
		l1[i] = 0;
	}
	
	for(i =0;i<array_size;i++)
	{
		l2[i] = (i+stride) % array_size;
	}
	
	int index =0;
	int j = 0;

	//hot HOT and TARGET
	for (i = 0; i < 10240; i++)
	{
		for(j = 0;j< (HOT_SIZE * 1024 / 4);j++)
		{
			index = l1[j];
		}
		for(j =0;j< (TARGET_SIZE*1024/4);j++)
		{
			index = l2[j];
		}
	}
	//hot HOT_SIZE
	for(i=0;i<10240;i++)
	{
		for(j = 0;j< (HOT_SIZE * 1024 / 4);j++)
		{
			index = l1[j];
		}
	}

	

	

	index = 0;
	for (index = 10; index != 0; index--) // hot index
	
	t1 = get_tsc();
	for(j = 0; j< TIMES; j++) // test 
	    index = l2[index];
	t2 = get_tsc();
	diff = 1.0 * diff_tsc(t1,t2) / TIMES;
	printf("%f\n",diff);

	free(l1);
	free(l2);
	free(discontinue);
	return 0;
}
int main()
{
	int i;
	for (i = 0; i < 15; i++)
	{
		test();
	}
	return 0;
}
