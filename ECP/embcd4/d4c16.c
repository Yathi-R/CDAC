/*String i/p o/p using getchar and putchar*/

#include<stdio.h>
#define MAX_CHAR 50

int main(){

    char str[MAX_CHAR];
    
    printf("Enter the string : ");
    fgets(str, MAX_CHAR, stdin);     // getting string using fgets

    printf("Entered string is ");
    puts(str);                       //printing the string using puts
        
return 0;
}