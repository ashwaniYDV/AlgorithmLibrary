/*
gcc -pthread main.c -o main
./main
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

// Declaration
int items = 0;

// Semaphore declaration
sem_t semEmpty, semFull;
// Mutex declaration
pthread_mutex_t mutexBuffer;

// Producer Section
void* produce(void* arg) {
    while (1) {
        // Produce
        sleep(rand() % 5);

        // Add to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        printf("Producer produces item. Items Present =  %d\n", ++items);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

// Consumer Section
void* consume(void* arg) {
    while (1) {
        // Remove from the buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        printf("Consumer consumes item. Items Present = %d\n", --items);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);

        // Consume
        sleep(rand() % 5);
    }
}

int main(int argv, char* argc[]) {
    int N; 
    printf("Enter the capacity of the buffer:\n");
    scanf("%d", &N);

    // thread declaration
    pthread_t producer, consumer;

    // mutex initialization
    pthread_mutex_init(&mutexBuffer, NULL);

    // semaphore initialization
    sem_init(&semEmpty, 0, N);
    sem_init(&semFull, 0, 0);


    // creation of process
    if (pthread_create(&producer, NULL, &produce, NULL) != 0) {
        perror("Failed to create thread");
    }
    // creation of consumer
    if (pthread_create(&consumer, NULL, &consume, NULL) != 0) {
        perror("Failed to create thread");
    }

    // joining the thread
    if (pthread_join(producer, NULL) != 0) {
        perror("Failed to join thread");
    }
    if (pthread_join(consumer, NULL) != 0) {
        perror("Failed to join thread");
    }

    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);

    return 0;
}


























// Full Fledged Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

// Declaration
int items = 0;

// Semaphore declaration
sem_t semEmpty, semFull;
// Mutex declaration
pthread_mutex_t mutexBuffer;

// Producer Section
void* produce(void* arg) {
    while (1) {
        // Produce
        sleep(rand() % 5);

        // Add to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        printf("Producer produces item. Items Present =  %d\n", ++items);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

// Consumer Section
void* consume(void* arg) {
    while (1) {
        // Remove from the buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        printf("Consumer consumes item. Items Present = %d\n", --items);
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);

        // Consume
        sleep(rand() % 5);
    }
}

int main(int argv, char* argc[]) {
    int N; 
    printf("Enter the capacity of the buffer:\n");
    scanf("%d", &N);

    // thread declaration
    pthread_t producer, consumer;

    // mutex initialization
    pthread_mutex_init(&mutexBuffer, NULL);

    // semaphore initialization
    sem_init(&semEmpty, 0, N);
    sem_init(&semFull, 0, 0);

    // declaration of attribute
    pthread_attr_t attr;
    // pthread_attr_t initialization
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // creation of process
    if (pthread_create(&producer, &attr, &produce, NULL) != 0) {
        perror("Failed to create thread");
    }
    // creation of consumer
    if (pthread_create(&consumer, &attr, &consume, NULL) != 0) {
        perror("Failed to create thread");
    }


    // destroying the pthread_attr
    pthread_attr_destroy(&attr);

    // joining the thread
    if (pthread_join(producer, NULL) != 0) {
        perror("Failed to join thread");
    }
    if (pthread_join(consumer, NULL) != 0) {
        perror("Failed to join thread");
    }

    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);

    // Exiting thread
    pthread_exit(NULL);

    return 0;
}
