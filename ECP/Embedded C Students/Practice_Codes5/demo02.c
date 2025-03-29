#include<stdio.h>

int *return_address1(int *pnum)         // return type - int *
{
    printf("ptr = %u\n", pnum);
    *pnum += 20;        // *pnum = *pnum + 20;
    return pnum;
}

int num1 = 10;

int *return_address2(int *pnum1)
{
    printf("ptr = %u\n", pnum1);
    *pnum1 += 20;
    return pnum1;
}

int *return_address3(void)
{
    int num2 = 10;
    int *pnum2 = &num2;
    *pnum2 += 20;
    printf("ptr = %u\n", pnum2);
    //return pnum2;
    return &num2;
}
// we should not return address of local variable from function

int main(void)
{
    int num = 10;

    //int *ptr = &num;
    //int* ptr1 = &num;
    int *ptr;
    printf("num = %d\n", num);

    ptr = return_address1(&num);

    printf("&num = %u\n", &num);
    printf("ptr = %u\n", ptr);

    printf("num = %d\n", *ptr);         // 30   

    ptr = return_address2(&num1);

    printf("&num = %u\n", &num1);
    printf("ptr = %u\n", ptr);

    printf("num1 = %d\n", num1);        // 30

    ptr = return_address3();

    printf("ptr = %u\n", ptr);
    printf("num2 = %d\n", *ptr);

    printf("Here\n");
    return 0;
}

