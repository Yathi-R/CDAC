/*Write a C program that prints the Fibonacci sequence up to n terms using a while loop.
The value of n should be provided by the user.*/

/*Fibnonacci sequence of first n terms*/

#include <stdio.h>

int main() {

    int n;

    // Taking user input
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    //checking for whole numbers
    if (n > 0) {
        printf("Fibonacci Sequence: ");

        int first = 0, second = 1, i = 1, next;

        // prints first n fibonacci sequence 
        while (i <= n) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
        i++;
        }
    }
    else {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    printf("\n");

return 0;
}
