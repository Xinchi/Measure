#include <time.h>
#include <stdio.h>

#include <sys/time.h>
#include <sys/resource.h>
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
int function0()
{
    return 0;
}
int function1(int a)
{
    return 0;
}
int function2(int a, int b)
{
    return 0;
}
int function3(int a, int b, int c)
{
    return 0;
}
int function4(int a, int b, int c, int d)
{
    return 0;
}
int function5(int a, int b, int c, int d, int e)
{
    return 0;
}
int function6(int a, int b, int c, int d, int e, int g)
{
    return 0;
}
int function7(int a, int b, int c, int d, int e, int g, int z)
{
    return 0;
}
int function8(int a, int b, int c, int d, int e, int g, int z, int z1)
{
    return 0;
}
int main(int argc, char** argv)
{
    if (argc == 1)
    {
	fprintf(stderr,"error\n");
	return 1;
    }
    char* tmp = argv[1];
    int number;
    int a[8];
    sscanf(tmp, "%d", &number);
    setpriority(PRIO_PROCESS, 0, -20);

    if (number == 0)
    {
	ts1 = get_tsc();
	function0();
	ts2 = get_tsc();
    }
    if (number == 1)
    {
	ts1 = get_tsc();
	function1(a[0]);
	ts2 = get_tsc();
    }
    if (number == 2)
    {
	ts1 = get_tsc();
	function2(a[0],a[1]);
	ts2 = get_tsc();
    }
    if (number == 3)
    {
	ts1 = get_tsc();
	function3(a[0],a[1],a[2]);
	ts2 = get_tsc();
    }
    if (number == 4)
    {
	ts1 = get_tsc();
	function4(a[0],a[1],a[2],a[3]);
	ts2 = get_tsc();
    }
    if (number == 5)
    {
	ts1 = get_tsc();
	function5(a[0],a[1],a[2],a[3],a[4]);
	ts2 = get_tsc();
    }
    if (number == 6)
    {
	ts1 = get_tsc();
	function6(a[0],a[1],a[2],a[3],a[4],a[5]);
	ts2 = get_tsc();
    }
    if (number == 7)
    {
	ts1 = get_tsc();
	function7(a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
	ts2 = get_tsc();
    }
    if (number == 8)
    {
	ts1 = get_tsc();
	function8(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
	ts2 = get_tsc();
    }
    printf("%ld",ts2-ts1);
}



