#include<stdio.h>

// Register storage class

// register int num;    // not allowed

int main(void)
{
    register int num = 10;
    // register keyword is used to make variable of register class
    // it requst your CPU for its register
    // if CPU register is not available, then that variable is treated as local variable

    num = 20;
    printf("num = %d\n", num);

    printf("ENter number : ");
    scanf("%d", &num);      // error: address of register variable 'num' requested
    // we can not demand for address of CPU registers


    return 0;
}