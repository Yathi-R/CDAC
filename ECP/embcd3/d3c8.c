/*to print numbers in reverse using for loop*/

#include<stdio.h>

int main(){

    int num;

    /*To get user input*/
    printf("Enter a integer number to print in reserse: ");
    scanf("%d", &num);

    /*loop to print fron num to 0*/
    for(num; num>=0; num--){
        printf("%d\n", num);
    }

return 0;
}