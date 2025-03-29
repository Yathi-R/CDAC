#include<stdio.h>
// Problem Statement
// Take one number from user and check whether it positive, negative or zero.

// Analysis:
// int num
// num == 0 - if it is true then num is zero
// num < 0 - if it is true then num is -ve
// num > 0 - if it is true then num is +ve

// Algorithm:
// 1. declare one int variable
// 2. Take value of num from user
// 3. check num with 0 or <0 or >0
// 4. Accordingly print msg on console

// Flow chart

// Psuedo code
// main()
//{
//  num
//  scanf(num)
//  if(num == 0)
//  printf();
//  if(num < 0)
//  printf();
// 
//}

int main(void)
{
    int num;

    printf("Enter number : ");
    scanf("%d", &num);

    if(num == 0)
    {
        printf("Number is zero\n");
    }
    // if you are having single line in any block then {...} are optional
    
    if(num < 0)
        printf("Number is -ve\n");

    if(num > 0)
        printf("Number is +ve\n");

    return 0;
}