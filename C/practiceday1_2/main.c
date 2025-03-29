#include<stdio.h>

#include "fun.c"


void main()
{
int a=100,b=10;

int ans = add(a,b);
printf("addition of no %d, %d is %d\n", a, b, ans);

ans = sub(a,b);
printf("Subtraction of no %d, %d is %d\n", a, b, ans);

ans = mul(a,b);
printf("Multiplication of no %d, %d is %d\n", a, b, ans);

float division = div(a,b);
printf("Division of no %d, %d is %0.2f\n", a, b, division);

}
