/*Write a C program to swap two integer variables using pointers and functions.*/

/* Swapping two integer variables using Function and pointers */

#include<stdio.h>

int getnum();
void swapfun(int *, int *);
void display(int *);

int main(){

    int num1 = getnum(); // Fun call to get 1st number
    int num2 = getnum(); // Fun call to get 2nd number

    printf("\nBefore swapping:\n");

    // Fun call to display numbers before swapping
    display(&num1);      
    display(&num2);

    swapfun(&num1, &num2); //Fun call to swap the numbers

    printf("\nAfter swapping:\n");

    // Fun call to display numbers After swapping
    display(&num1);
    display(&num2);


return 0;
}


// fun to get a number
int getnum(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    return n;
}

// fun to swap two numbers
void swapfun(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

//fun to print a number
void display(int *n){
    printf("Value of the number: %d\n", *n);
}
