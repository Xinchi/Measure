#include "tsc.h"
#include <time.h>
#include <stdio.h>


#define TSC_OVERHEAD 1
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

unsigned long ts1, ts2;
int function1()
{
    ts2 = get_tsc();
    return 0;
}

int function2(int a, int b)
{
    ts2 = get_tsc();
    return 0;
}

int main(int argc, char** argv)
{
    if (!strcmp	)
    
    ts1 = get_tsc();
    function1();
    printf("%ld\n",ts2-ts1);
    
}



