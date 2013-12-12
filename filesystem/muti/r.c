#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>


#define BLKSIZE 512
int main(int argc, char** argv)
{
    int fd;


    //fd = open("/dev/sda3", O_RDONLY);
    if (argc < 3)
	exit (1);

    if (fd < 0)
    {
	printf("error to open\n");
    }


    unsigned char* block;
    block = memalign(BLKSIZE, BLKSIZE);

    int n;
    unsigned long long total = 0;
    unsigned long long file_size = 0;
    file_size = atoi(argv[1]);
    struct timeval t1, t2;
    unsigned long long interval = 0;
    printf("file_size=%dMB\n", file_size);

    pid_t pid;
    int i;

    int count;

    count = atoi(argv[2]);

    int offset;
    pid_t child[count];
    printf("count=%d\n",count);
    for (i = 0; i < count; i++)
    {
	pid = fork();
	if (pid)
	{
	    child[i] = pid;

	    //printf("%d\n",pid);
	    continue;
	}
	else
	{
	    fd = open("/dev/sda3", O_RDONLY | O_DIRECT);
	    printf("child=%d\n",i);
	    offset = lseek64(fd, i * file_size * 1024 * 1024 / 512 * 512, 0);
	    printf("offset = %d\n", offset);
	    total = 0;
	    gettimeofday(&t1);
	    while (1)
	    {
		n = read(fd, block, BLKSIZE);
		if (n < 0)
		{
		    printf("error\n");
		}
		total += n;
		//if ((total / 1024 / 1024) > file_size)
		if ((total / 1024 / 1024) > 30)
		{
		    printf("done\n");
		    break;
		}
		//printf("%llu\r", total / 1000 / 1000);
		//printf("%d\n",i);
	    }
	    gettimeofday(&t2);
	    interval = (t2.tv_sec - t1.tv_sec) * 1000000 + 
		       (t2.tv_usec - t1.tv_usec);
	    printf("\n");
	    //printf("%d,latency=usec/MB,%llu\n", i ,interval / file_size);
	    printf("%d,latency=usec/MB,%llu\n", i ,interval / 30);
	    sleep (5);
	    return 0;
	}
    }
    for (i = 0; i < count; i++)
    {
	waitpid(child[i]);
    }
    close(fd);

    return 0;
}
