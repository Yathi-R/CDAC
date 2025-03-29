#include<stdio.h>

int main(void)
{
    int ret;
    int num;
    char ch;

    //int printf("format string", ...);
    // printf returns how many characters are printed on console
    ret = printf("CDAC\n");

    printf("ret = %d\n", ret);

    //int scanf("format string", ...);
    // scanf returns how many variables are scanned from console
    printf("Enter number and character : ");
    ret = scanf("%d %c", &num, &ch);

    //printf("%d\n", printf("ret = %d\n", ret));
    ret = printf("ret = %d\n", ret);

    printf("%d\n", ret);
    return 0;
}