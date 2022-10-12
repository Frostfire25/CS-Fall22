/// Practice #1 - Alexander Elguezabal - 9/14/2022
/// Practice1.c

#include<stdio.h> 
#include<stdlib.h>
#include"Practice1.h" // define the header file  
#include <unistd.h> // Unix import

// Implementations
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

// Prints the values from a point
void print_point(struct point p) {
    printf("(%.1f,%.1f)", p.x, p.y);
}

// Reflects a point over the y axis
void reflect_over_y(struct point *p) {
    p->x = p->x*-1;
}

// Returns two points added together.
struct point translate(struct point *a, struct point *b) {
    struct point ret;
    ret.x = a->x + b->x;
    ret.y = a->y + b->y;

    return ret;
}

// Does the math to get a tip price
double getTip(double price, double tipPercentage) {
    return price + (price * tipPercentage);
}

// Swaps the values of two integers
int swap(int* a, int* b) {
    int q = *a;
    *a = *b;
    *b = q;

    return 0;
}

// Creates a new array based off of parameter sz
int* allocate_array(int sz) {
    int* array = malloc(sz * sizeof(int));

    for(int i = 0; i < sz; i++) {
        array[i] = 0;
    }

    return array;
}

// Prints the content in an array based of parameter size
int print_array(int* array, int size) {
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

// Populates an array based off of parameter val
int populate_array(int* array, int val, int size) {
    for(int i = 0; i < size; i++) {
        array[i] = val;
    }
}


int main()   // define the main function  
{  
    printf("Hello World!");  // print the statement.  

    printf("\n Bill: $40, Tip: 0.25. Total Price: %0.2f", getTip(40.0, 0.25));

    int a = 5;
    int b = 1;
    printf("\nA: %d, B: %d", a, b);
    swap(&a, &b);
    printf("\nA: %d, B: %d", a, b);

    // Allocates a new array into memory with parameter size
    int *array = NULL;
    array = allocate_array(10);

    // Populates an array based off of paramater val
    populate_array(array, 7, 10);

    // Prints the array
    print_array(array, 10);

    // Frees the space from the array
    free(array);

    // Create a new point
    struct point point1;
    point1.x = 10;
    point1.y = 15;

    // Prints the point
    printf("\n");
    print_point(point1);

    // Reflect the point and print it.
    reflect_over_y(&point1);
    printf("\n");
    print_point(point1);

    // Create second point
    struct point point2;
    point2.x = 21;
    point2.y = 97;

    // Display the translate function by creating a new point, point3, and displaying its value
    struct point point3;
    point3 = translate(&point1, &point2);
    printf("\n");
    print_point(point3);


    printf("\n\nPress Enter to close.");
    getchar();

    return 0;
}  