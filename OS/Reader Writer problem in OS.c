// https://practice.geeksforgeeks.org/problems/explain-reader-writer-problem-in-synchronization-with-code
// gcc -pthread main.c -o main

/*
PROBLEM :  suppose we have a shared memory area with the basic constraints detailed above. 
It is possible to protect the shared data behind a mutual exclusion mutex, in which case no two threads can access the data at the same time. 
However, this solution is sub optimal, because it is possible that a reader R1 might have the lock, and then another reader R2 requests access. 
It would be foolish for R2 to wait until R1 was done before starting its own read operation; instead, R2. 
This is the motivation for the first readers-writers problem, 
in which the constraint is added that no reader shall be kept waiting if the share is currently opened for reading. 
This is also called readers-preference, with its solution:


READER CODE:
--------------
semaphore wrt = 1;
semaphore mutex = 1;
readcount = 0;

wait(mutex);
        readcount := readcount + 1;
        if readcount = 1 then wait(wrt);
signal(mutex);
       .....
        reading is performed
        .....
wait(mutex);
        readcount := readcount - 1;
        if readcount = 0 then signal(wrt);
signal(mutex);

 

WRITER CODE:
--------------
wait(wrt);
        . . .
        writing is performed
        . . .
signal(wrt);
*/

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>
#include<semaphore.h>

pthread_mutex_t x, wsem;
pthread_t tid;
int readCnt;

void intialize() {
    pthread_mutex_init(&x, NULL);
    pthread_mutex_init(&wsem, NULL);
    readCnt = 0;
}

void * reader(void * param) {
    int waitTime;
    waitTime = rand() % 5;

    printf("\nReader is trying to enter");
    pthread_mutex_lock(&x);
    readCnt++;
    if (readCnt == 1) {
        pthread_mutex_lock( & wsem);
    }
    printf("\n%d Reader is inside ", readCnt);
    pthread_mutex_unlock( & x);
    
    /**/
    sleep(waitTime);
    /**/

    pthread_mutex_lock( & x);
    readCnt--;
    if (readCnt == 0)
        pthread_mutex_unlock( & wsem);
    pthread_mutex_unlock( & x);
    printf("\nReader is Leaving");
}

void * writer(void * param) {
    int waitTime;
    waitTime = rand() % 3;
    
    printf("\nWriter is trying to enter");
    pthread_mutex_lock( & wsem);
    printf("\nWrite has entered");
    
    /**/
    sleep(waitTime);
    /**/

    pthread_mutex_unlock( & wsem);
    printf("\nWriter is leaving");
    sleep(30);
    exit(0);
}

int main() {
    int n1, n2, i;
    printf("Enter the no of readers: ");
    scanf("%d", & n1);
    printf("Enter the no of writers: ");
    scanf("%d", & n2);

    for (i = 0; i < n1; i++) {
        pthread_create( & tid, NULL, reader, NULL);
    }
    for (i = 0; i < n2; i++) {
        pthread_create( & tid, NULL, writer, NULL);
    }
    sleep(30);
    exit(0);
}
