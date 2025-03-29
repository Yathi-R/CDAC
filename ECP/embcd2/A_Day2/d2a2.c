/*Write a C program for calculator with basic operations.*/

/*Calculator with basic operations*/

#include<stdio.h>

int main(){

    int a = 100, b = 10, result;

    result = a + b;                                  /*Addition*/
    printf("Sum of %d and %d is %d\n", a, b, result);

    result = a - b;                                  /*Subtraction*/
    printf("Sub of %d and %d is %d\n", a, b, result);

    result = a * b;                                  /*Multiplication*/  
    printf("Mul of %d and %d is %d\n", a, b, result);

    result = a / b;                                  /*Division*/
    printf("Div of %d and %d is %d\n", a, b, result);

    result = a % b;                                   /*Modulous*/
    printf("Mod of %d and %d is %d\n", a, b, result);

    return 0;
}
