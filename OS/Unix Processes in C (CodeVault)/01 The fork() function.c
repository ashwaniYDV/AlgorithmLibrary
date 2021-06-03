#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int id = fork();
    if (id == 0) {
        printf("We are in the child process\n");
    } else {
        printf("We are in the parent process and process id of created child process is: %d\n", id);
    }
    return 0;
}
