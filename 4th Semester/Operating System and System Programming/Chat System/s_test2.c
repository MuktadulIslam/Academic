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

#define MAX 512

int clientCount = 0;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct client{

	int index;
	int sockID;
	struct sockaddr_in clientAddr;
	int len;

};

void * doNetworking(void * ClientDetail){

	struct client* clientDetail = (struct client*) ClientDetail;
//	int index = clientDetail -> index;
//	int clientSocket = clientDetail -> sockID;

	int connfd = clientDetail -> sockID;
    int clientNo = clientDetail -> index;
    printf("Client %d connected.\n",clientNo + 1);
    char buff[MAX];
    int n;
    // infinite loop for chat
//    while(1) {
//        sleep(2);
//        bzero(buff, MAX);
//
//        // read the message from client and copy it in buffer
//        read(connfd, buff, sizeof(buff));
//        // print buffer which contains the client contents
//        if (strncmp("exit", buff, 4) == 0) {
//            printf("Client %d is disconnected by itself.....\n", clientNo);
//            break;
//        }
//        printf("From client-%d: %s", clientNo,buff);
//
//
//        // server sending message to client
//        strcat(buff," from server\n");
//        printf("\n\t To client-%d: %s",clientNo, buff);
//        write(connfd, buff, sizeof(buff));
//        printf("waiting for message from client...................\n\n");
//
//        sleep(2);
//
//    }
//    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//    printf("Waiting for new connection.......\n\n\n");


	return NULL;

}

int main(){

	struct client Client[1024];
    pthread_t thread[1024];

    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddr;

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = htons(INADDR_ANY);


	if(bind(serverSocket,(struct sockaddr *) &serverAddr , sizeof(serverAddr)) == -1) return 0;

	if(listen(serverSocket,1024) == -1) return 0;

	printf("Server started listenting on port 8080 ...........\n");

	int len;
	while(1){
        struct sockaddr_in clientAddr;
        struct client *c = (struct client*) malloc(sizeof(struct client));
        pthread_t t;

		c->sockID = accept(serverSocket, (struct sockaddr*) &clientAddr, &len);
		c->index = clientCount++;

		pthread_create(&t, NULL, doNetworking, (void *) c);
		pthread_join(t, NULL);

	}

//	for(int i = 0 ; i < clientCount ; i ++)
//		pthread_join(thread[i],NULL);

}
