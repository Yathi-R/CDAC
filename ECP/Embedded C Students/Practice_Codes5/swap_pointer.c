#include<stdio.h>

// swap two local variable using function

void swap(int *, int *);

int main(void)
{
    int num1, num2;

    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    printf("main :: before swap :: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("main :: after swap :: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

void swap(int *pnum1, int *pnum2)
{
   // num1 --> *pnum1
   // num2 --> *pnum2
   int temp = *pnum1;
   *pnum1 = *pnum2;
   *pnum2 = temp;
}