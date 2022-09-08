#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_THREAD 10

sem_t sem_lock;
int shared_variable=0;


void* counter(void* arg)
{
    int i = * (int*) arg;

//	   	sem_wait(&sem_lock);		//semaphore lock
        sleep(2);

        if(i%2 == 0)
            printf("  Thread No: %d is increase shared_variable by %d. Now shared_variable = %d\n",i+1, i+1, shared_variable+i+1);
        else
            printf("  Thread No: %d is decrease shared_variable by %d. Now shared_variable = %d\n",i+1, i+1, shared_variable-i-1);

//	   	sem_post(&sem_lock);		//semaphore unlock
}


int main()
{
	sem_init(&sem_lock,0,1);			//semaphore initializ
	pthread_t threads[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; i++) {
		int *tid;
		tid = (int *) malloc(sizeof(int));
		*tid = i;
		pthread_create(&threads[i], NULL, counter, (void*)(tid));
	}
    for (int i=0; i<MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    sem_destroy(&sem_lock);			//semaphore destroy

	return 0;
}
