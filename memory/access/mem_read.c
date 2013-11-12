#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "math.h"
#include <stdlib.h>

#define TIMES 10
#define REPETITION 1000000
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

unsigned long diff_tsc(unsigned long t1, unsigned long t2)
{
    return (t2 - t1 -67);
}



int main(int arvc, char* argv[])
{
	int num1,num2;
	sscanf (argv[1],"%d",&num1);
	sscanf (argv[2],"%d",&num2);
	unsigned long t1;
	unsigned long t2;
	unsigned long long sum;
	sum = 1;
	double diff;

//str is in byte, while size is in kb

	//int stride = num1/4;//stride = 4mb
	int stride = num1;
	int n;
	for (n = 0;n<TIMES;n++)
	{
	        //int size = (pow(2,num2)/4)*pow(2,10);//8kb
		int size = (pow(2,num2))*pow(2,10);//8kb
	        int i;
	        //int a[array_size];
	        long* a = malloc(size); 
		long* b = a;
		//printf("%d\n",sizeof(long*));
		//printf("%d\n",sizeof(long));
	    
	        for(i = 0;i< (size / 8);i++)
	        {
		    
		    //a[i] = (i+stride)%size * 4 + &a[i];
		    //a[i] = (int)(&(a[i]) + (stride % size));
		    //a[i] = (long)(a);
		    //a[i] = (long)(&a[i] + stride % size);
		    a[i] = (long)(&a[(i + stride / 8) % (size / 8)]);
                	//	a[i] = 2;
	        } 
	        int index =0;
		int j = 0;
		t1 = get_tsc();
		for(j = 0;j<REPETITION;j++)
		{
		    b = *b;
		}
		t2 = get_tsc();
		if (sum == 1)
		{
		    sum = 0;
		}else{
		    sum += diff_tsc(t1, t2);
		    //printf("%f\n", 1.0 *  diff_tsc(t1, t2) / REPETITION);
		}
		free(a);
	}
	diff = 1.0 * sum / TIMES / REPETITION;
	printf("%f\n",diff);
}
