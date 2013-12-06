#include <stdio.h>
#include <unistd.h>

#define MAX_LOOP 99999999
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

int main()
{
    register int i;
    unsigned long t1, t2;
    t1 = get_tsc();
    for (i = 0; i < MAX_LOOP; i++);
    t2 = get_tsc();

    printf("%lu\n", (t2 - t1));
    printf("%f\n", 1.0 * (t2 - t1)/MAX_LOOP);
    return 0;
}
