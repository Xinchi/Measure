#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("/dev/sda6", O_RDONLY);

    if (fd < 0)
    {
	printf("error to open\n");
    }

    unsigned char block[2048];

    int n;
    while (1)
    {
	n = read(fd, block, 2048);
    }

    printf("%d\n",n);
    close(fd);
    return 0;
}
