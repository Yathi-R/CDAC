#include<stdio.h>

int main(void)
{
    int num, i;
    char ch;

    printf("Enter character : ");
    scanf("%c", &ch);

    printf("Enter number : ");
    scanf("%d", &num);

    i = 1;
    while( i <= num)
    {
        if(i == 4)
        {
            i++;
            continue;
        }
        printf("%d - %c\n", i, ch);
        i++;
    }

    return 0;
}