#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

#define NUMBER_OF_THREAD 10

int shared_value = 5;

sem_t read_cout, write_cout;
int number_of_reader = 0, number_of_writer = 0;

void * reader(void * argv) {
    printf("\t\t Reader-%d is arrived\n", *(int*)argv);
    sem_wait(&write_cout);
    sem_wait(&read_cout);

    printf("Reader-%d ----- reading shared value x as %d\n", *(int*)argv, shared_value);
    sleep(0.5);
    printf("Reader-%d ----- reading is done.\n", *(int*)argv);

    sem_post(&read_cout);
    sem_post(&write_cout);
}

void * writer(void *argv) {
    printf("\t\t Writer-%d is arrived\n", *(int*)argv);

    sem_wait(&write_cout);
    number_of_writer++;

    if(number_of_writer == 1) sem_wait(&read_cout);

    shared_value += 5;
    printf("Writer-%d ---- writing shared value x as %d\n", *(int*)argv, shared_value);
    sleep(0.5);
    printf("Writer-%d ---- writing done.\n", *(int*)argv);

    number_of_writer--;
    sem_post(&write_cout);

    if(number_of_writer == 0) sem_post(&read_cout);
}

int main(void) {
    sem_init(&read_cout, 0, 1);
    sem_init(&write_cout, 0, 1);
    pthread_t t[NUMBER_OF_THREAD];
    int writerNO = 0, readerNO = 0;

    int i;
    for(i=0 ; i<NUMBER_OF_THREAD ; i++) {
        int *tid;
		tid = (int *) malloc(sizeof(int));

		if(rand()%2 == 0) {
            *tid = writerNO++;
            pthread_create(&t[i], NULL, writer, (void*) tid);
        }
        else {
            *tid = readerNO++;
            pthread_create(&t[i], NULL, reader, (void*) tid);
        }
    }

    for(i=0  ; i<NUMBER_OF_THREAD ; i++) {
        pthread_join(t[i], NULL);
    }
}

