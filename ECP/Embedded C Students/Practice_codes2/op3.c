#include<stdio.h>

int main(void)
{
    int res = 10;

    res+=5;  //   res + 5

    printf("res = %d\n", res);

    res=+5;     // res = +5
    printf("res = %d\n", res);
    
    return 0;
}