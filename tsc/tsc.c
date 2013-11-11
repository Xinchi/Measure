#include <stdio.h>
#include <time.h>
#define DEBUG 1
inline unsigned long tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

#ifdef DEBUG
int main()
{
    unsigned long t1, t2;
    //sleep (1);
    t1 = tsc();
    t2 = tsc();
    printf("%ld\n",t2 - t1);
}
#endif
