#include<stdio.h>

/*
    Pointer
    - is a normal variable which is used to store address of any other variable
    - type of pointer variable is decided by which type of address you are storing in it.
    - eg. integer type data - int
          address of int type variable is also of same type

    - syntax
        <data type> *<pointer variable name>
    eg. int *ptr;

    & - address of / referance / direction  
      - if you want to assign address of any variable to pointer type variable then this operator can be used

    * - value at / dereferance / redirection
      - if you want to get value of any variable by using pointer variable then this operator can be used
*/

int main(void)
{
    /*
    unsigned int ptr = 1243656;

    unsigned int *ptr = 1243656;
*/


    int num = 10;
    char ch = '#';
    double d = 3.14;

    int *pnum;
    char *pch = &ch;
    double *pd = &d;

    pnum = &num;

    printf("pnum = %u, &num = %u\n", pnum, &num);
    printf("pch = %u, &ch = %u\n", pch, &ch);
    printf("pd = %u, &d = %u\n", pd, &d);

    printf("num = %d, *pnum = %d\n", num, *pnum);
    printf("ch = %c, *pch = %c\n", ch, *pch);
    printf("d = %lf, *pd = %lf\n", d, *pd);

    printf("sizeof(pnum) = %d\n", sizeof(pnum));
    printf("sizeof(pch) = %d\n", sizeof(pch));
    printf("sizeof(pd) = %d\n", sizeof(pd));

    printf("sizeof(int *) = %d\n", sizeof(int *));
    printf("sizeof(char *) = %d\n", sizeof(char *));
    printf("sizeof(float *)) = %d\n", sizeof(float *));
    printf("sizeof(double *)) = %d\n", sizeof(double *));

    // irrespective of data type size of pointer is 8 bytes on 64 bit compiler
    // irrespective of data type size of pointer is 4 bytes on 32 bit compiler
    return 0;
}