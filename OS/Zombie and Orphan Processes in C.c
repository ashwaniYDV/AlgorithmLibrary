// https://www.geeksforgeeks.org/zombie-and-orphan-processes-in-c/

/*
What is the zombie process?
----------------------------
A process that has finished the execution but still has an entry in the process table to report to its parent process is known as a zombie process. 
A child process always first becomes a zombie before being removed from the process table. 
The parent process reads the exit status of the child process which reaps off the child process entry from the process table.

What are orphan processes?
----------------------------
A process whose parent process no more exists (either finished or terminated without waiting for its child process to terminate) is called an orphan process.
*/



// A C program to demonstrate Zombie Process.
// Child becomes Zombie as parent is sleeping when child process exits.

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    // Fork returns process id in parent process
    pid_t child_pid = fork();

    // Parent process
    if (child_pid > 0)
        sleep(50);

    // Child process
    else
        exit(0);

    return 0;
}











// A C program to demonstrate Orphan Process.
// Parent process finishes execution while the child process is running. The child process becomes orphan.

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Create a child process
    int pid = fork();

    if (pid > 0)
        printf("in parent process");

    // Note that pid is 0 in child process and negative if fork() fails
    else if (pid == 0) {
        sleep(30);
        printf("in child process");
    }

    return 0;
}
