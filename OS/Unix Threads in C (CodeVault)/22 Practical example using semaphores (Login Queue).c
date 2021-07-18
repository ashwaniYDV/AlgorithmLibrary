// https://youtu.be/Q79uEdKNVGY


/*
THREAD_NUM = no of people trying to login

sem_init(&semaphore, 0, 5);
here 5 = size of login queue
*/



#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 16

sem_t semaphore;

void* routine(void* args) {
    printf("(%d) Waiting in the login queue\n", *(int*)args);
    sem_wait(&semaphore);
    printf("(%d) Logged in\n", *(int*)args);
    sleep(rand() % 5 + 1);
    printf("(%d) Logged out\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 5);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semaphore);
    return 0;
}
