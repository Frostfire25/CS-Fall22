#include<stdio.h> 
#include<conio.h>  
#include<stdlib.h>
#include"Project1.h" // define the header file  
#include <unistd.h> // Unix import

// Implementations
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

int main() {

    char command[100];
    // Do REPL command
    while(true) {
        scanf(" >> ", command);


    }

    return 0;
}