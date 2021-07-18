#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

void* routine() {
    for (int i = 0; i < 1000000; i++) {
        mails++;
        // read mails
        // increment
        // write mails
    }
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2;
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_join(p1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 4;
    }
    printf("Number of mails: %d\n", mails);
    return 0;
}















// Java Example
class Counter {
    static public int cnt = 0;
}

class MultithreadingDemo extends Thread {
    @Override
    public void run() {
        try {
            for(int i = 0; i < 10000; i++) {
                Counter.cnt++;
            }
            // Displaying the thread that is running
            System.out.println("Thread " + Thread.currentThread().getId() + " is running");
        }
        catch (Exception e) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}


public class Main {
    public static void main(String[] args) {
        int n = 2;
        for (int i = 0; i < n; i++) {
            MultithreadingDemo object = new MultithreadingDemo();
            object.start();
        }
        try {
            Thread.sleep(3000);
        } catch (Exception e) {
            System.out.println("Error!!!");
        }
        System.out.println(Counter.cnt);
    }
}
