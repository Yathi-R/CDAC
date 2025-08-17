/*Write a C program that reverses a given integer using a do-while loop.*/

/*reversing user given integer using do-while loop*/

#include<stdio.h>

int main(){

    int n, reversed = 0, reminder;

    //getting integer number from user
    printf("Enter a integer number:");
    scanf("%d", &n);

    // using do-while loop to reverse the integer
    do{
        reminder = n % 10;
        reversed = reversed * 10 + reminder;
        n /= 10;
    } while( n!= 0);

    //Displaying the reversed number
    printf("Reversed number is %d\n", reversed);

return 0;
}

