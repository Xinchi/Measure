#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pthread.h>

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
int diff(int a)
{
    t2 = get_tsc();
    return 0;
}
    unsigned long t1;
    unsigned long t2;
 
int main()
{
   unsigned long diff;
    pid_t pid;

    setpriority(PRIO_PROCESS, 0, -20);

    pthread_t p;
    t1 = get_tsc();
    pthread_create(&p, NULL, &diff, NULL);
    //t2 = get_tsc();
    printf("%ld",t2 - t1);


    return 0;
}
