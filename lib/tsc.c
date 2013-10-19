#include "tsc.h"
#include <time.h>
#include <stdio.h>

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


unsigned long test_tsc_overhead()
{
    timestamp1 = get_tsc();
    timestamp2 = get_tsc();
    return diff_tsc(timestamp1, timestamp2);
}



