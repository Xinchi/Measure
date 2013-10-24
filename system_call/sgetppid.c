#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/syscall.h>


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
    setpriority(PRIO_PROCESS, 0, -20);

    pid_t pid;
    pid = getppid();
    pid = syscall(SYS_getppid);
    pid = syscall(SYS_getppid);

    pid = getppid();

    t1 = get_tsc();
    //pid = getppid();
    pid = syscall(SYS_getppid);
    t2 = get_tsc();

    diff = diff_tsc(t1, t2);
    printf("%ld",diff);


    return 0;
}
