#include<stdio.h>

int main(void)
{
    char ch = 'B';
    int num = 66;

    printf("ch = %c\n", ch);
    printf("ASCII Value of A = %d\n", 'A');

    printf("ASCII Value of %c = %c\n", ch, ch);

    printf("ASCII Value of %c = %i\n", ch, ch);

    printf("ASCII value of \\n = %d\n", '\n');
    printf("ASCII value of \\t = %d\n", '\t');
   

    printf("Associated character to %d = %c\n", num, num);
    return 0;
}