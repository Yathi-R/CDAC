#include<stdio.h>

int main(void)
{
    int num = 10;

    int *ptr = &num;

    printf("num = %d\n", num);

    *ptr = 20;

    printf("num = %d\n", num);

    printf("num = %d\n", *ptr);

    printf("num = %d\n", &num);

    return 0;
}