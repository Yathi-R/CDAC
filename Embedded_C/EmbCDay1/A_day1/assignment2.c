/*Swapping the integrs without using other variables*/

#include<stdio.h>

int main(){

    int a=10, b=20;
    printf("Values before swapping: a is %d and b is %d\n", a,b);

    /*swapping without another var*/
    a = a+b;
    b = a-b;
    a = a-b;
    
    printf("Values after swapping: a is %d and b is %d\n", a,b);
    return 0;
}