/*Write a C program that calculates the maximum of three numbers using the conditional
(ternary) operator. The program should handle cases where the numbers are equal.*/

/* Ternary oper to check max of number including cases of equal*/

#include<stdio.h>

int main(){

    int a = -33, b = -33, c = 0, temp, max;

    printf("Numbers are %d %d %d\n", a, b, c);

    // using ternary operator to check MAX
    temp = (a > b || a == b)? a : b;        /*checks if a is >= b and assigns a or b to temp*/
    max = (temp > c || temp == c)? temp : c; /*checks if temp is >= c and assigns temp or c to max*/
    
    printf("Max num is %d\n", max);

return 0;
}