#include<stdio.h>
// Take nunber and character from user and print character that number times.

int main(void)
{
    int num, i;
    char ch;

    printf("Enter character : ");
    scanf("%c", &ch);

    printf("Enter number : ");
    scanf("%d", &num);

    i = 1;
    while(i++ <= num)
        printf("%-4c", ch);

    return 0;
}