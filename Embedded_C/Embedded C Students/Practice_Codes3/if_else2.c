#include<stdio.h>
// Take two numbers from user and check maximum and minimum number.


int main(void)
{
    int num1, num2;

    printf("Enter two numbers :  ");
    scanf("%d %d", &num1, &num2);

    if(num1 > num2)
        printf("num1 is maximum\n");
    else 
        printf("num2 is maximum\n");

    //Conditional operator
    // (condition) ? statement 1 : statement 2;

    num1 > num2 ? printf("num1 is maixmum\n") : printf("num2 is maximum\n");
    
    return 0;
}