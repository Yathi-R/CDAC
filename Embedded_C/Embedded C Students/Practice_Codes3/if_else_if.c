#include<stdio.h>

int main(void)
{
    int num;

    printf("Enter number : ");
    scanf("%d", &num);

    // check if number is +ve or -ve
    if(num == 0)
    {
        printf("Number is zero\n");
    }
    else if(num < 0)
    {
        // if block
        // if condition is true then this block will get executed
        printf("Number is -ve\n");
    }
    else
    {
        // else block
        // if condition id false then this block will get executed
        printf("Number is +ve\n");
    }

    return 0;
}