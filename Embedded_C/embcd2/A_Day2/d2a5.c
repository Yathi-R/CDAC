/*Write a C program that uses unary operators to increment and decrement a variable. Initialize
a variable, use both pre-increment and post-increment operators, and print the results*/

/*Unary operators: Increment and decrement*/

#include<stdio.h>

int main(){

    //Initializing a variable
    int num = 3;

    printf("Value of num: %d\n", num);

    ++num;                                       /*pre incrementing using unary oper ++*/
    printf("Pre incremented value: %d \n", num);

    --num;                                       /*pre decrementing using unary oper --*/
    printf("Pre decremented value: %d \n", num);

    num++;                                      /*post incrementing using unary oper ++*/
    printf("Post incremented value: %d \n", num);

    num--;                                      /*post decrementing using unary oper --*/
    printf("Post decremented value: %d \n", num);

return 0;
}