#include<stdio.h>

int main(void)
{
    int res, num1 = 10, num2 = 20;

    // Relational operators
    res = num1 == num2;         //0
    printf("res = %d\n", res);
    
    res = num1 != num2;         //1
    printf("res = %d\n", res);
    
    res = num1 <= num2;         //1
    printf("res = %d\n", res);
    
    res = num1 > num2;         //0
    printf("res = %d\n", res);

    // Logical operators
    num1 = 0; num2 = 10;

    res = !num1;        // 1
    printf("res = %d\n", res);

    res = !num2;        // 0
    printf("res = %d\n", res);
    // 0 - 1
    // 1 - 0

    res = num1 && num2;        // 0
    printf("res = %d\n", res);
    // 00 - 0
    // 01 - 0
    // 10 - 0
    // 11 - 1
    // In case of logical AND - if first operand is 0, then second operand will not be checked
    // and result will be 0

    res = num1 || num2;        // 1
    printf("res = %d\n", res);
    // 00 - 0
    // 01 - 1
    // 10 - 1
    // 11 - 1
    // In case of logican OR - If first operand is 1, then second operand will not be checked
    // and result is 1


    res = (300, 200, 100);
    printf("Res = %d\n", res);

    res = 10, 20, 30;
    printf("Res = %d\n", res);

    return 0;
}