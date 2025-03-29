


// Take nunber and character from user and print character that number times.
// do thhis with recursion

// function which takes two arguments
// arg1 - character to be printed
// arg2 - count 

#include<stdio.h>
void print_char(char ch, int num)
{
    if(num == 0)        // terminating condition
        return;
    printf("%-4c", ch);
    print_char(ch, num-1);
}

int main(void)
{
    int num;
    char ch;

    printf("Enter character : ");
    scanf("%c", &ch);

    printf("Enter number : ");
    scanf("%d", &num);

    print_char(ch, num);        // #, 5
    return 0;
}