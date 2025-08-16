#include<stdio.h>

// swap two variables using function

void swap(void);

int num1, num2;

int main(void)
{
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    printf("main :: Before swap :: num1 = %d, num2 = %d\n", num1, num2);
    swap();
    printf("main :: After swap :: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

void swap(void)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}