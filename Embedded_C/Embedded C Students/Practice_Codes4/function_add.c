#include<stdio.h>

// Take two numbers from user and do addition of it (use different functions for each functinality).

double accept_number(void);
void print_result(double);
double add_numbers(double, double);

int main(void)
{
    double num1, num2, res;

    num1 = accept_number();
    num2 = accept_number();

    res = add_numbers(num1, num2);

    print_result(res);

    return 0;
}

double accept_number(void)
{
    double num;
    printf("Enter value : ");
    scanf("%lf", &num);
    return num;
}
void print_result(double result)
{
    printf("Result = %lf\n", result);
}
double add_numbers(double n1, double n2)
{
    double res = n1 + n2;
    return res;
}