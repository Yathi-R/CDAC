#include<stdio.h>

// 2. if you want to return multiple values from function, you can use pointer variable

int calculate(int num1, int num2, int *pdiff, int *pmul);

int main(void)
{
    int num1, num2, sum, diff, mul;

    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    sum = calculate(num1, num2, &diff, &mul);
    //diff = calculate(num1, num2);

    printf("sum = %d\n", sum);
    printf("diff = %d\n", diff);
    printf("mul = %d\n", mul);

    return 0;
}
int calculate(int num1, int num2, int *pdiff, int *pmul)
{
    *pmul = num1 * num2;
    *pdiff = num1 - num2;
    return num1 + num2;
}
