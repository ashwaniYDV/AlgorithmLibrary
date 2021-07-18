// https://youtu.be/ZpRN3XQY4AA

/*
Note: These codes are not free from race conditions. It is just used to show the difference between mutex and binary semaphores.

We cannot lock a mutex in one thread and unlock it from another thread.
But we can do this for semaphores.
*/



// Using mutex, it breaks after some iterations
/*
If you try to execute this program you might seem that it works, but it might work for a while untill it breaks.
For mutexes locking and unlocking from different threads is just undefined behaviour and after sometime it simply breaks.
But this is not the case with semaphores. 
This is because mutexes have a concept of ownership. So whenever a thread is locking a mutex, the mutex expects the unlock also be by the same thread.
If it isn't then its undefined behaviour. And undefined behaviour is really bad.

But in semaphores, we can sem_wait in one thread and sem_post in some another thread without any issue.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

pthread_mutex_t mutexFuel;
sem_t semFuel;
int fuel = 50;

void* routine1(void* args) {
    while (1) {
        pthread_mutex_lock(&mutexFuel);
        fuel += 50;
        printf("Current value is %d\n", fuel);
    }
}

void* routine2(void* args) {
    while (1) {
        pthread_mutex_unlock(&mutexFuel);
        // 5ms sleep
        usleep(5000);
    }
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semFuel, 0, 1);
    pthread_mutex_init(&mutexFuel, NULL);

    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (i % 2 == 0) {
            if (pthread_create(&th[i], NULL, &routine1, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &routine2, NULL) != 0) {
                perror("Failed to create thread");
            }   
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    
    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&semFuel);
    return 0;
}

























// Working fine with binary semaphore

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 4

pthread_mutex_t mutexFuel;
sem_t semFuel;
int fuel = 50;

void* routine1(void* args) {
    while (1) {
        sem_wait(&semFuel);
        fuel += 50;
        printf("Current value is %d\n", fuel);
    }
}

void* routine2(void* args) {
    while (1) {
        sem_post(&semFuel);
        // 5ms sleep
        usleep(5000);
    }
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semFuel, 0, 1);
    pthread_mutex_init(&mutexFuel, NULL);

    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (i % 2 == 0) {
            if (pthread_create(&th[i], NULL, &routine1, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &routine2, NULL) != 0) {
                perror("Failed to create thread");
            }   
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }

    pthread_mutex_destroy(&mutexFuel);
    sem_destroy(&semFuel);
    return 0;
}
