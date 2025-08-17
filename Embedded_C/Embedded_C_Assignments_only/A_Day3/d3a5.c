/*Write a C program to compute the factorial of a given positive integer using a for loop.*/

/*Finding factorial of +ve number using for loop*/

#include <stdio.h>

int main() {

    int n;
    unsigned long long int factorial = 1;

    printf("Enter a positive integer less than 21: ");
    scanf("%d", &n);

    //checking if n is 0 or 1
    if (n ==0 || n ==1){
        printf("The Factorial of %d is 1.\n", n);
    }
    
    // Checking if the input is a positive integer and less than 21
    else if (n > 1 && n < 21) {

        // Calculating the factorial using a for loop
        for (int i = 1; i <= n; i++) {
            factorial *= i;  
        }

        printf("The factorial of %d is: %llu\n", n, factorial);
        
    } 
    
    else {
        printf("Invalid, given value is either negative or greater than 20 \n");
        return 1;
    }

    return 0;
}
