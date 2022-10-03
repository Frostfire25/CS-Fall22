/// Practice #4 - Alexander Elguezabal - 9/14/2022
/// Practice4.c

#include<stdlib.h>
#include<stdio.h> 
#include<conio.h>  
#include"Practice4.h" // define the header file  
#include <unistd.h> // Unix import
#include <stdlib.h>
#include <pthread.h>

// Implementations
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}