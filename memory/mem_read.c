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
    return (t2 - t1);
}



int main()
{
	unsigned long t1;
	unsigned long t2;
	unsigned long diff;

	//str is in byte, while size is in kb
	int* l1; 
	int* discontinue; 
	int* l2;
	int stride = 1024/4;
	l1 = malloc(1024*8);
	discontinue = malloc(1024*1024*3);
	l2 = malloc(1024*20);

	int i;
	for(i=0;i<8*1024/4;i++)
	{
		l1[i] = 0;
	}
	
	int index =0;
	int j = 0;

	int tmp;
	for (i = 0; i < 10240; i++)
	{
		for(j = 0;j< (4 * 1024 / 4);j++)
		{
			index = a[j];
		}
	}




	index = 0;
	for (index = 10; index != 0; index--) // hot index
	
	t1 = get_tsc();
	for(j = 0; j< 1000; j++) // test 
	    index = a[index];
	t2 = get_tsc();
	diff = diff_tsc(t1,t2) / 1000;
	printf("%ld\n",diff);

	return 0;
}
