#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include<errno.h>

#define PORT 5050
#define MAX 512
#define MAX_MESSAGES 1000

struct client{

	int index;
	int sockID;
	struct sockaddr_in clientAddr;
	int len;

};
char circlerQueue[MAX_MESSAGES][MAX];
int front = -1, rear = -1;

// return 0 for successful push, -1 for overflow
int push(char *str) {
    if(front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    }
    else if(rear == MAX-1 && front != 0) {
        rear = 0;
    }
    else if(rear != MAX-1) {
        rear++;
    }
    else if((rear+1)%MAX_MESSAGES == front) {
//        Queue overflow
        return -1;
    }

    strcpy(circlerQueue[rear], str);
    return 0;
}

// return index of the value for successful pop, -1 for underflow
int pop(void) {
    int index ;

    if(front == -1) {
        index = -1
    }
    else if(front == MAX_MESSAGES-1) {
        index = front;
        front = 0;
    }
    else if(front == rear) {
        index = front;
        front = -1;
        rear = -1;
    }
    else {
        index = front;
        front++;
    }

    return index;
}


void * doNetworking(void * ClientDetail){

	struct client* clientDetail = (struct client*) ClientDetail;
	int index = clientDetail -> index;
	int clientSocket = clientDetail -> sockID;

	printf("Client %d connected.\n",index + 1);




	char buff[MAX];
    int n;
    int clientNo = clientDetail->index;
    int connfd = clientDetail->sockID;
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

	return NULL;
}

void* receive_message(void *client_struct) {

    struct client* clientDetail = (struct client*) ClientDetail;
	int index = clientDetail->index;
	int clientSocket = clientDetail->sockID;

	printf("Client %d connected.\n",index);


	char buffer[MAX];
    while(1) {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(clientSocket, buff, sizeof(buff));
        // print buffer which contains the client contents
        if (strncmp("exit", buff, 4) == 0) {
            printf("Client %d is disconnected by itself.....\n", index);
            break;
        }
        printf("From client-%d: %s", index,buff);
        push(buffer);


        // server sending message to client
        write(clientSocket, buff, sizeof(buff));
    }

}

int main(){

	int serverSocket;
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));


    // socket create and verification
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }

    // assign IP, PORT
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }

    // Now server is ready to listen and verification
    if ((listen(serverSocket, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    printf("Server started listenting on port %d ...........\n", PORT);




    // For accepting clients request
	int len, clientCount = 0;
	pthread_t thread;
	while(1){
        struct sockaddr_in clientAddr;
        struct client *Client = (struct client*) malloc(sizeof(struct client));

		Client->sockID = accept(serverSocket, (struct sockaddr*) &clientAddr, &len);
		Client->index = ++clientCount;

		pthread_create(&thread, NULL, receive_message, (void *) Client);
	}
    pthread_exit(NULL);
}
