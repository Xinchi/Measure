#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "math.h"
#include <stdlib.h>
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

unsigned long diff_tsc(unsigned long t1, unsigned long t2)
{
    return (t2 - t1 - 67);
}

#define BLOCKSIZE 10000
#define READTIME 100
#define FILE_SIZE 1000000000
int main()
{
	unsigned long t1, t2;
	int i;
	int	fd = open("test.img", O_RDONLY, 0);
	
	for(int j = 0;j<READTIME;j++)
	{
		read(fd, &i, sizeof(int));
	}
	
	t1 = get_tsc();
	//operation
	printf("%ld\n",t1);

	lseek(fd, FILE_SIZE-1, SEEK_SET);
	int bytesRead = 0;
	printf("hello\n");
	int bytes;
	while(1){
		lseek(fd, -2*BLOCKSIZE, SEEK_CUR); 
		bytes = read(fd, &i, BLOCKSIZE);
//		printf("bytes = %d\n", bytes);
		if (bytes <= 0 || bytesRead >= FILE_SIZE)
       		break;
    	bytesRead += bytes;
//		printf("%d\n",bytesRead);
	}
	t2 = get_tsc();
}
