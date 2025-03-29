#include<stdio.h>

int main(void)
{
    int res = 10, num1 = 20;

    res += 5;   //res = res + 5     --> res = 10 + 5 = 15
    printf("res = %d\n", res);

    res += num1;    //res = res + num1      -> res = 15 + 20 = 35
    printf("res = %d\n", res);

    return 0;
}