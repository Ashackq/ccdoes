#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 5

sem_t mutex, wrt, reade;
int sharedData = 50;
int readersc = 0;

void *reader(void *arg) {
    int readerId = *(int *)arg;
    printf("Reader %d has enterded\n", readerId);
    
        sem_wait(&mutex);
        sem_wait(&reade);
        readersc++;
        if (readersc == 1) {
            sem_wait(&wrt);
        }

        sem_post(&reade);
        sem_post(&mutex);

        printf("Reader %d is reading: %d\n", readerId, sharedData);
        sem_wait(&reade);
        readersc--;
        if (readersc == 0) {
            sem_post(&wrt);
        }
        sem_post(&reade);
        sleep(rand() % 3);
    
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writerId = *(int *)arg;
    printf("Writer %d is trying to enter!\n", writerId);
	
    
        sem_wait(&wrt);

        if (sharedData > 0) {
            sharedData--;
            printf("Writer %d is writing: %d\n", writerId, sharedData);   
        } else {
            printf("cannot write further\n");
            sem_post(&wrt); 
           
        }

        sem_post(&wrt);
        printf("Writer %d is out!\n", writerId);
    

    pthread_exit(NULL);
}


int main() {

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    sem_init(&reade, 0, 1);

//creating threads
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int readerIds[NUM_READERS], writerIds[NUM_WRITERS];

    for (int i = 0; i < NUM_READERS; i++) {
        readerIds[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &readerIds[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writerIds[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writerIds[i]);
    }

	printf("Here\n");

//joining threads
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    sem_destroy(&reade);

    return 0;
}

