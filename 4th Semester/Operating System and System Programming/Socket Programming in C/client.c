#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 7777       // the port client will be connecting to
#define MAXDATASIZE 512 // max number of bytes we can get at once


void chat_with_server(int sockfd)
{
	char buff[MAXDATASIZE];
	int n;
	while(1) {
		printf("To Server : ");
		fgets(buff,MAXDATASIZE-1,stdin);

		write(sockfd, buff, sizeof(buff));
		if (strncmp("exit", buff, 4) == 0) {
            printf("Client is disconnected by itself.....\n");
            break;
        }

        printf("waiting for message from server...................\n");
		read(sockfd, buff, sizeof(buff));
		if (strncmp("exit", buff, 4) == 0) {
            printf("Client is disconnected by server.....\n");
            break;
        }
        printf("\tFrom server: %s\n", buff);
	}
}


int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *server;
    struct sockaddr_in server_addr; // connector's address information

    if (argc != 2) {
        printf("usage: client hostname (IP address)\n"); exit(1);  }

    if ((server=gethostbyname(argv[1])) == NULL) {  // get the host info
        printf("ERROR, no such host\n");  exit(0);  }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");  exit(0);  }

    bzero((char *) &server_addr, sizeof(server_addr));  // zero the rest of the struct
    server_addr.sin_family = AF_INET;    // host byte order
    server_addr.sin_port = htons(PORT);  // short, network byte order
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("ERROR connecting");  exit(0);  }

    chat_with_server(sockfd);
    close(sockfd);

    return 0;
}



