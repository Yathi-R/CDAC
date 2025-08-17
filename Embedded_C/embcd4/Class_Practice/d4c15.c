/*Char i/p o/p using getchar and putchar*/

#include<stdio.h>

int main(){

    char ch;
    printf("Enter a character : ");
    ch = getchar();               // getting a char using getchar

    if (ch == ' '){
        printf("Entered char is whitespace");
        putchar('\n');
    }
    else{
        printf("Entered character is ");
        putchar(ch);              //printing the char using putchar
        putchar('\n');
    }
return 0;
}