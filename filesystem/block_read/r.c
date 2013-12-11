#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char** argv)
{
    int fd;


    fd = open("/dev/sda3", O_RDONLY);
    if (argc < 2)
	exit (1);

    if (fd < 0)
    {
	printf("error to open\n");
    }

    unsigned char block[4000];

    int n;
    unsigned long long total = 0;
    unsigned long long file_size = 0;
    file_size = atoi(argv[1]);
    struct timeval t1, t2;
    unsigned long long interval = 0;
    printf("file_size=%dMB\n", file_size);
    gettimeofday(&t1);
    while (1)
    {
	n = read(fd, block, 4000);
	total += n;
	if ((total / 1000 / 1000) > file_size)
	{
	    break;
	}
	printf("%llu\r", total / 1000 / 1000);
    }
    gettimeofday(&t2);
    interval = (t2.tv_sec - t1.tv_sec) * 1000000 + 
	       (t2.tv_usec - t1.tv_usec);
    printf("\n");
    printf("latency=usec/MB,%llu\n", interval / file_size);


    lseek(fd, 0, 0);

    //fd = open("/dev/sda3", O_RDONLY);
    printf("after the hot\n");

    total = 0;
    
    gettimeofday(&t1);
    while (1)
    {
	n = read(fd, block, 4000);
	total += n;
	if ((total / 1000 / 1000) > file_size)
	{
	    break;
	}
	printf("%llu\r", total / 1000 / 1000);

    }
    gettimeofday(&t2);
    interval = (t2.tv_sec - t1.tv_sec) * 1000000 + 
	       (t2.tv_usec - t1.tv_usec);
    printf("latency=usec/MB,%llu\n", interval / file_size);

    printf("%d\n",n);
    close(fd);
    return 0;
}
