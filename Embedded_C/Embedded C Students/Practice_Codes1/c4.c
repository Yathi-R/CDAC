#include<stdio.h>

int main(void)
{
    int num1 = 10;
    int num2 = 20;
    char ch = 'A';
    // printf - is a library function which is used to print on console
    // printf(<format string>, <list of variables>...);

    printf("\tHello DESD\n");
    printf("Welcome to \"C-DAC\"\n");

    printf("%i\n",num1);
    printf("num1 = %d\n", num1);

    printf("%d %d\n", num1, num2);
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("num1 = %d, num2 = %d\n", num2, num1);

    printf("%d %d %c\n", num1, num2, ch);
    return 0;
}