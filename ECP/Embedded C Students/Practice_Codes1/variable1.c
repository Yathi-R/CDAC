#include <stdio.h>

// Global variable
int var = 10;

void display() {
    // Local variable with the same name
    int var = 20;
    printf("Inside function: Local var = %d\n", var);
}

int main(void) {
    printf("Inside main: Global var = %d\n", var);
    display();
    return 0;
}