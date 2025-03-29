/*Write a C program that demonstrates the use of bitwise AND, OR, and XOR operators.
Initialize two integers and apply these operators to them, then print the results.*/

/*Bitwise AND, OR and XOR operations*/

#include<stdio.h>

int main(){

    int num1 = 525, num2 = 1000, result = 0; /* binary of 525: 1000001101 & 1000: 1111101000*/

    //Bitwise ADD operation
    result = num1 & num2;
    printf("%d AND %d: %d\n", num1, num2, result); /*o/p 1000001000 i.e 520*/

    //Bitwise OR operation
    result = num1 | num2;
    printf("%d OR %d: %d\n", num1, num2, result); /*o/p 1111101000 i.e 1005*/

    //Bitwise XOR operation
    result = num1 ^ num2;
    printf("%d XOR %d: %d\n", num1, num2, result); /*o/p 0111100101 i.e 485*/

return 0;
}
