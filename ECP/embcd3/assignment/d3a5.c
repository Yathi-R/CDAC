/*Finding factorial of +ve number using for loop*/

#include <stdio.h>

int main() {

    int n;
    unsigned long long int factorial = 1;

    printf("Enter a positive integer less than 21: ");
    scanf("%d", &n);

    // Checking if the input is a positive integer and less than 21
    if (n > 0 && n < 21) {

        // Calculating the factorial using a for loop
        for (int i = 1; i <= n; i++) {
            factorial *= i;  
        }

        printf("The factorial of %d is: %llu\n", n, factorial);
        
    } 
    
    else {
        printf("Invalid, given value is either negative, zero or greater than 20 \n");
    }

    return 0;
}
