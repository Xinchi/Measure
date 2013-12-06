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

int sockfd, newsockfd;
int sock_pool[64];
pthread_t thread[64];
int count;

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
	printf("%d\n", n);
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
