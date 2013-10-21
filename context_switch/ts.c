#include <stdio.h>
#include <unistd.h>
#include <sched.h>

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
    int i;

    i = 0;
    pid_t pid;

    pid = fork();
    
    if (pid)
    {
	for (i = 0; i < 100; i++)
	{
	    printf("1\n");
	    sched_yield();
	} 
    }
    else
    {
	for (i = 0; i < 100; i++)
	{
	    printf("2\n");
	    sched_yield();
	}
    }
    return 0;
}
