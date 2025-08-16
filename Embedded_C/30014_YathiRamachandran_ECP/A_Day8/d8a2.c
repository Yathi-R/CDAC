/*Write a C program to print the maximum number among 2 using macro-MAX.*/

/*Fining Max amoung 2 numbers using Macro*/

#include<stdio.h>

//Defining Macro MAX to find maximun using ternary operation
#define MAX(num1, num2) num1 > num2 ? num1 : num2;

int main(){

    int num1, num2;

    //Getting user input of Num1 and num2
    printf("Enter 2 integers: ");
    scanf("%d %d", &num1, &num2);

    //Using Macro MAX to find the maximum and assigning to max
    int max= MAX(num1, num2);

    //printing the maximum number
    printf("Maximum among %d and %d is %d\n", num1, num2, max);

    return 0;
}