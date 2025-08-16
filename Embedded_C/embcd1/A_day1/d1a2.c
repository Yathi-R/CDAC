/*Initialise and assign integer values to 2 variables named x and y. Write a C code to swap
their values without using any other variable. Print the values before and after
swapping.*/

/*Swapping the integrs without using other variables*/

#include<stdio.h>

int main(){

    //assigning 2 integer values
    int x = 10, y = 20;

    //printing vales before swapping
    printf("Values before swapping: x is %d and y is %d\n", x, y);

    /*swapping without another var*/
    x = x + y;
    y = x - y;
    x = x - y;
    
    //Printing values after swapping
    printf("Values after swapping: x is %d and y is %d\n", x, y);

    return 0;
}