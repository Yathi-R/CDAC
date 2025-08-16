#include<stdio.h>

/*
ptr + 1 = ptr + 1 * SF(ptr)
ptr + 2 = ptr + 2 * SF(ptr)

ptr + n = ptr + n * SF(ptr)

ptr - 1 = ptr - 1 * SF(ptr)
ptr - 2 = ptr - 2 * SF(ptr)

ptr - n = ptr - n * SF(ptr)
*/

int main(void)
{
    int num = 10;
    char ch = 'A';

    int *ptr = &num;
    char *ptr1 = &ch;

    printf("ptr = %u\n", ptr);
    printf("ptr + 1 = %u\n", ptr + 1);  //ptr + 1 * SF(ptr)  ==>  ptr + 1 * 4  ==> ptr + 4
    printf("ptr + 2 = %u\n", ptr + 2);  //ptr + 2 * SF(ptr)  ==>  ptr + 2 * 4  ==> ptr + 8

    printf("ptr - 1 = %u\n", ptr - 1);  //ptr - 1 * SF(ptr)  ==>  ptr - 1 * 4  ==> ptr - 4
    printf("ptr - 2 = %u\n", ptr - 2);  //ptr - 2 * SF(ptr)  ==>  ptr - 2 * 4  ==> ptr - 8

    printf("ptr1 = %u\n", ptr1);
    printf("ptr1 + 1 = %u\n", ptr1 + 1);  //ptr1 + 1 * SF(ptr1)  ==>  ptr1 + 1 * 1  ==> ptr1 + 1
    printf("ptr1 + 2 = %u\n", ptr1 + 2);  //ptr1 + 2 * SF(ptr1)  ==>  ptr1 + 2 * 1  ==> ptr1 + 2

    printf("ptr1 - 1 = %u\n", ptr1 - 1);  //ptr1 - 1 * SF(ptr1)  ==>  ptr1 - 1 * 1  ==> ptr - 1
    printf("ptr1 - 2 = %u\n", ptr1 - 2);  //ptr1 - 2 * SF(ptr1)  ==>  ptr1 - 2 * 1  ==> ptr - 2

    return 0;
}