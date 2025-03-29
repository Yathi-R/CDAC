#include<stdio.h>

/*
    type casting
    - changing the meaning of existing datatype
    - this change is not permenant
    - it is only for that operation
    
*/

int main(void)
{
    int res, num1 = 9, num2 = 2;
    float res1;

    //res = num1 / num2;
    //printf("num1 = %d, num2 = %d, res = %d\n", num1, num2, res);

    res1 = num1 / num2;
    printf("num1 = %d, num2 = %d, res1 = %f\n", num1, num2, res1);

    res1 = (float)num1 / num2;
    printf("num1 = %d, num2 = %d, res1 = %f\n", num1, num2, res1);

    return 0;
}