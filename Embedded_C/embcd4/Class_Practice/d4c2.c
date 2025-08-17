#include <stdio.h>

long long int factorial(int);

int main() {

    int n;
    
    printf("Enter a positive integer less than 21: ");
    scanf("%d", &n);

    //checking if n is inbetween 0 to 21
    if (n >= 0 && n < 21) {

        printf("The factorial of %d is: %lld\n", n, factorial(n));
        
    } 
    
    else {
        printf("Invalid, given value is either negative or greater than 20 \n");
    }

    return 0;
}

// Calculating the factorial using recursion
long long int factorial(int n){
    
    if (n == 0 || n == 1){
        return 1;
    }

    return n*factorial(n-1);
}
