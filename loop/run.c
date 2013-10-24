#include <stdio.h>
#include <unistd.h>

#define MAX_LOOP 15000
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

int main()
{
    int i;
    unsigned long t1, t2;
    t1 = get_tsc();
    for (i = 0; i < MAX_LOOP; i++);
    t2 = get_tsc();

    printf("%ld\n", (t2 - t1)/MAX_LOOP);
    return 0;
}
