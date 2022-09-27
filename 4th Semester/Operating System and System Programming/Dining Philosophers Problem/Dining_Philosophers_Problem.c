#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define PHILOSOPHERS 5
#define MAX_THREAD 10

sem_t chopsticks[PHILOSOPHERS];


void* getRice(void* arg)
{
    int PhilosopherID = * (int*) arg;
    int leftChopsticks, rightChopsticks;
    rightChopsticks = PhilosopherID;
    if(PhilosopherID == 0) leftChopsticks = PHILOSOPHERS-1;
    else leftChopsticks = PhilosopherID-1;

    int leftSemaphorValue, rightSemaphorValue;
    sem_getvalue(&chopsticks[leftChopsticks], &leftSemaphorValue);
    sem_getvalue(&chopsticks[rightChopsticks], &rightSemaphorValue);

    while(1) {
        if(leftSemaphorValue != 0 && rightSemaphorValue != 0) {
            sem_wait(&chopsticks[leftChopsticks]);		//semaphore lock
            printf("Philosopher-%d took his left chopsticks\n", PhilosopherID);

            sem_wait(&chopsticks[rightChopsticks]);		//semaphore lock
            printf("Philosopher-%d took his right chopsticks\n", PhilosopherID);
            break;
        }
        else if(leftSemaphorValue == 0) {
            sem_wait(&chopsticks[leftChopsticks]);		//semaphore lock

            // Chicking that right chopsticks is using or not
            sem_getvalue(&chopsticks[rightChopsticks], &rightSemaphorValue);
            if(rightSemaphorValue != 0)
                printf("Philosopher-%d took his left chopsticks\n", PhilosopherID);
            else {
                printf("\tPhilosopher-%d wanted take his right chopsticks but as it is taken so he put his left chopsticks\n", PhilosopherID);
                sem_post(&chopsticks[leftChopsticks]);
                sleep(0.5);
                continue;
            }

            sem_wait(&chopsticks[rightChopsticks]);		//semaphore lock
            printf("Philosopher-%d took his right chopsticks\n", PhilosopherID);
            break;
        }
        else {
            sem_wait(&chopsticks[rightChopsticks]);		//semaphore lock

            // Chicking that right chopsticks is using or not
            sem_getvalue(&chopsticks[leftChopsticks], &leftSemaphorValue);
            if(leftSemaphorValue != 0)
                printf("Philosopher-%d took his left chopsticks\n", PhilosopherID);
            else {
                printf("\tPhilosopher-%d wanted take his left chopsticks but as it is taken so he put his right chopsticks\n", PhilosopherID);
                sem_post(&chopsticks[rightChopsticks]);
                sleep(0.5);
                continue;
            }

            sem_wait(&chopsticks[leftChopsticks]);		//semaphore lock
            printf("Philosopher-%d took his left chopsticks\n", PhilosopherID);
            break;
        }
    }

    // eating time
    sleep(2);


    sem_post(&chopsticks[leftChopsticks]);		//semaphore unlock
    printf("\t\t Philosopher-%d put his left chopsticks\n", PhilosopherID);
    sem_post(&chopsticks[rightChopsticks]);		//semaphore unlock
    printf("\t\t Philosopher-%d put his right chopsticks\n", PhilosopherID);
}


int main(){
    for(int i=0 ; i<PHILOSOPHERS ; i++)
        sem_init(&chopsticks[i],0,1);			//semaphore initializ

	pthread_t threads[MAX_THREAD];


	for (int i = 0; i < MAX_THREAD; i++) {
		int *tid;
		tid = (int *) malloc(sizeof(int));

		// Finding which Phliosopher get hungry by rand fuction
		*tid = rand()%5;

		pthread_create(&threads[i], NULL, getRice, (void*)(tid));
	}

    for (int i=0; i<MAX_THREAD; i++)
        pthread_join(threads[i], NULL);


    for(int i=0 ; i<PHILOSOPHERS ; i++)
        sem_destroy(&chopsticks[i]);			//semaphore destroy
	return 0;
}
