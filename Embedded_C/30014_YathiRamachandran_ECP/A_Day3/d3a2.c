/*Write a C program to find out maximum number out of 3 numbers entered by user.*/

/* finding maximum among 3 user given numbers*/

#include<stdio.h>

int main() {
    int num1, num2, num3, max;

    // Getting user input
    printf("Enter 3 integer numbers: \n");
    scanf("%d%d%d", &num1, &num2, &num3);

    // Finding maximum number
    max = num1;
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }

    printf("The maximum number is %d\n", max);
    
return 0;
}
