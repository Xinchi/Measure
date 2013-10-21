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
    unsigned long t1, t2;

    i = 0;
    pid_t pid;

    pid = fork();
    if (pid)
    {
	t1 = get_tsc();
	sched_yield();
	printf("%ld\n",t1);
	//give up in parent. Child has its time pieces
    }
    else
    {
	t2 = get_tsc();
	printf("%ld",t2);
    }
}
