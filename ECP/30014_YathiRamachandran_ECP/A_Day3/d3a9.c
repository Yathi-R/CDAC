/*Write a C program that prints a right-angled triangle pattern of stars (*) with n rows
using nested for loops. The number of rows n should be provided by the user.*/

/*printing a right-angled triangle pattern of stars (*) 
using nested for loops with user defined n rows*/

#include <stdio.h>

int main() {
    int n;

    // Taking user input
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Outer loop for n rows
    for (int i = 1; i <= n; i++) {

        // Inner loop for printing stars
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

return 0;
}
