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

    int str = pow(2,0);//stride = 4mb
    int ex = 2;
    for (;ex<12;ex++)
	{

    int size = pow(2,3);//8kb
    //unsigned int array_size = (size/4)*pow(2,10);
    unsigned int array_size = 4 * 1024 /4 ;   
	int stride = 1;
    int i;
    //int a[array_size];
    int* a = malloc(array_size * 4); 
    
    for(i = 0;i<array_size;i++)
    {
	a[i] = (i+stride) % array_size;
//	a[i] = 2;
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
		for (index = 10; index != 0; index--)
		t1 = get_tsc();
		for(j = 0; j< 1000; j++)
		    index = a[index];
		t2 = get_tsc();
		diff = diff_tsc(t1,t2) / 1000;
		printf("%ld\n",diff);
	}
	return 0;
}
