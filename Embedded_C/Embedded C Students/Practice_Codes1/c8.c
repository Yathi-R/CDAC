#include<stdio.h>
/*
    scanf - it is used to take value from user
    syntax : scanf("<Format string>", [List of addresses of variables]);
*/


int main(void)
{
    int num;
    int num1, num2;
    float flt;
    char ch;

    printf("Enter number : ");
    scanf("%d", &num);

    printf("ENter character : ");
    scanf("%*c%c", &ch);

    printf("num = %d, ch = %c\n", num, ch);


    printf("Enter one integer value : ");
    scanf("%d", &num);

    printf("num = %d\n", num);

    printf("Enter two integer numbers : ");
    scanf("%d %d", &num1, &num2);

    printf("num1 = %d, num2 = %d\n", num1, num2);

    printf("Enter one integer and one float : ");
    scanf("%d %f", &num, &flt);

    printf("num = %d, flt = %.2f\n", num, flt);

    return 0;
}