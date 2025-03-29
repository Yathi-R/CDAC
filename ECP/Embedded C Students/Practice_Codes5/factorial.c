#include<stdio.h>

// declaration of functions
int accept_number(void);
int factorial(int);
void print_result(int);

// main function - entry point function
int main(void)
{
    int num;

    num = accept_number();

    print_result(factorial(num));

    // fact = factorial(num);
    // print_result(fact);

    return 0;
}

// definition of functions
int accept_number(void)
{
    int num;
    printf("Enter number : ");
    scanf("%d", &num);
    return num;
}
int factorial(int num)
{
    int i, fact = 1;
    for(i = 1 ; i <= num ; i++)
        fact *= i;
    return fact;
}
void print_result(int res)
{
    printf("factorial = %d\n", res);
}