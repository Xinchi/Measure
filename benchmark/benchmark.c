#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char** argv)
{
    char* exec_prg;
    if (argc == 1) // not input
    {
	printf("usage:\n\tbenchmark exec_binary\n");
	return 1;
    }
    exec_prg = argv[1];

    fprintf(stderr,"exec_prg=%s\n",exec_prg);


    pid_t pid;
    pid = fork();
    if (pid)
    {
	waitpid(pid, NULL, 0);
	fprintf(stderr,"test_done=%d\n",pid);
    }
    else
    {
	fprintf(stderr,"exec\n");
	sleep(1);
    }
    return 0;

}
