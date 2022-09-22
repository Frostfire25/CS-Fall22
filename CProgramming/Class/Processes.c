#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {


    pid_t pid;
    pid = fork();

    if(pid < 0) {
        fprintf(stderr, "Fork failed! \n");
        return 1;
    }

    // The child process
    else if(pid == 0) {
        printf("Hello from the child!\n");

    } 

    // Parent process
    else {
        printf("Parent is here\n");
    }

}
