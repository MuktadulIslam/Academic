#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 512
#define PORT 7777
#define SA struct sockaddr

// Function designed for chat between client and server.
void chat_with_client(int connfd, int clientNo)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    while(1) {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        if (strncmp("exit", buff, 4) == 0) {
            printf("Client %d is disconnected by itself.....\n", clientNo);
            break;
        }
        printf("From client-%d: %s", clientNo,buff);


        // server sending message to client
        strcat(buff," from server\n");
        printf("\n\t To client-%d: %s",clientNo, buff);
        write(connfd, buff, sizeof(buff));
        printf("waiting for message from client...................\n\n");
    }
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("Waiting for new connection.......\n\n\n");
}


// Driver function
int main()
{
   pid_t   p, sid;

    p = fork();

    if (p < 0) {
        exit(EXIT_FAILURE);
    } else if (p > 0) {
        exit(EXIT_SUCCESS);
    }

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }



    int sockfd, connfd;
    struct sockaddr_in servaddr;
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");



    int len,clientNo = 0;
    pid_t pid;
    len = sizeof(struct sockaddr_in);
    while(1) {

//        sleep(1);
        struct sockaddr_in clientSock;
        // Accept the data packet from client and verification
        connfd = accept(sockfd, (SA*)&clientSock, &len);
        if (connfd < 0) {
            printf("server accept failed...\n");
            exit(0);
        }
        else{
            printf("server accept client - %d\n", ++clientNo);
            printf("-------------------------------------------------------\n");
        }

        // Creating a new process that will continue with a client
        pid = fork();
        // Parent process will return to the loop to connect another client
        if(pid > 0) continue;

        // Function for chatting between client and server
        chat_with_client(connfd, clientNo);
        close(connfd);

        // One process should run only one with client
        if(pid == 0) exit(1);
    }

    close(sockfd);
}
