/*Write a C program that demonstrates the difference between pre-increment (++x) and
post-increment (x++) operators. Print the values before and after each operation.*/

/*To demonstrate pre and post increment by printing the value before & after*/

#include<stdio.h>

int main(){

    int x=100; // Initializing the variable
    printf(" the value of x is %d\n",x);
    
    /*post increment*/
    x++;
    printf(" the value of x post increment is %d\n",x);
    
    /*pre increment*/
    printf(" the value of x pre increment is %d\n", ++x);
    return 0;
}