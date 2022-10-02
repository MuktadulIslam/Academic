#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<errno.h>
#include <pthread.h>
#include <semaphore.h>

#define SLICES 8
#define STUDENTS 5
#define THREADS 10

sem_t pizza, deliver;
int pizzaSlices[SLICES], num_pizzaSlices;

void *deliverPizza() {
    while(1) {
        sem_wait(&deliver);
        while(num_pizzaSlices != 0) {
            sleep(2);
        }

        // 3 sec for delivery time
        printf("Pizza is being delivered........\n");
        sleep(3);
        for(int i=0 ; i<SLICES ; i++) pizzaSlices[i] = 1;
        num_pizzaSlices = SLICES;

        sem_post(&deliver);
    }
}

void * eatingPizza(void *x) {
    int stuNo = *(int*) x;

    sem_wait(&pizza);
    if(num_pizzaSlices == SLICES) {
        sem_wait(&deliver);
    }
    while(num_pizzaSlices == 0) {
        sleep(0.5);
    }
    num_pizzaSlices--;
    printf("%d student is eating one slice of pizza...\n", stuNo);
    sleep(0.5);

    if(num_pizzaSlices == 0) {
        sem_post(&deliver);
        sleep(0.5);
    }
    sem_post(&pizza);
}


int main(void) {
    sem_init(&pizza, 0, 1);
    sem_init(&deliver, 0, 1);
    int i,j;
    pthread_t thread[THREADS], deliverThread;

    pthread_create(&deliverThread, NULL, deliverPizza, NULL);

    for(i=0 ; i < THREADS ; i++){
        int j = rand()%STUDENTS + 1;

		pthread_create(&thread[i], NULL, eatingPizza, (void*)&j);
	}

	pthread_join(deliverThread, NULL);
	for(i=0; i<THREADS; i++)
        pthread_join(thread[i], NULL);
}
