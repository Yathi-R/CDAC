/*Write a C program to input a number from user and find its factorial with help of
functions.*/

/*Finding factorial for user given number using Fun & Pointers*/

#include <stdio.h>

long long int factorial(int *);
int getnum();

int main() {

    int n = getnum(); //function call to get a number

    //checking if n is inbetween 0 to 21
    if (n >= 0 && n < 21) {

        printf("The factorial of %d is: ", n);
        printf("%lld\n", factorial( &n )); //fun call using argu by reference
        
    } 
    
    else {
        printf("Invalid, given value is either negative or greater than 20 \n");
    }

    return 0;
}

// fun to get a number
int getnum(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}

// recursion fun to find factorial with call by reference
long long int factorial(int *n){
    
    if ( *n == 0 || *n == 1){
        return 1;
    }
    int temp = *n;
    (*n)--;
    return temp * factorial(n);
}
