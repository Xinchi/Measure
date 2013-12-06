/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

int sockfd, newsockfd;
int sock_pool[64];
pthread_t thread[64];
int count;
unsigned long long total;

void sig_handler(int signo)
{
    int i;
    if (signo == SIGINT)
    {
	printf("signal\n");
	close(sockfd);
	for (i = 0; i < count; i++)
	{
	    pthread_detach(thread[i]);
	    close(sock_pool[i]);
	}
	exit(0);
    }
}

void* timer()
{
    struct timeval now;
    struct timeval old;
    unsigned long long t;
    gettimeofday(&now);
    while (1)
    {
	/*
	old = now;
	gettimeofday(&now);

	t = (now.tv_sec - old.tv_sec)* 1000000 + 
	    (now.tv_usec - old.tv_usec);
	    */
	printf("Mbps=,%f\n", (total * 8.0 / 1000000));
	total = 0;
	sleep(1);
    }
}
void* receiver(void* input)
{
    int n;
    char buffer[20480];
    int socket;
    socket = *(int*)input;
    bzero(buffer,20480);
    while (1)
    {
	n = read(socket,buffer,20480);
	if (!n)
	{
	    break;
	}
	total += n;
	//printf("%d\n", n);
    }
    printf("close connection\n");
}
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
	printf("not init the signal\n");
	return 1;
    }
     int portno;
     count = 0;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,10);
     clilen = sizeof(cli_addr);
     total = 0;
     pthread_t p_summary;
     pthread_create(&p_summary, 0, timer,0);
     while (1)
     {
	 newsockfd = accept(sockfd, 
		     (struct sockaddr *) &cli_addr, 
		     &clilen);
	 printf("new client\n");
	 if (newsockfd < 0) 
	      error("ERROR on accept");
	 sock_pool[count] = newsockfd;
	 pthread_create(&(thread[count]), 0, receiver, 
			&(sock_pool[count]));
	 //bzero(buffer,256);
	 //n = read(newsockfd,buffer,255);
	 count++;
     }
     return 0; 
}
