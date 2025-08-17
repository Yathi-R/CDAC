/*Write a C program that demonstrates the concept of variable scope by using local and
global variables. Show how changes to a global variable affect the output in different
functions.*/

/*Scope of global and local varibale*/

#include<stdio.h>

int globV = 100; /*global variable initialization*/

/* Function definition*/
int fun(int a, int b); 
int modifiedfun(int a, int b);

int main(){

    int localV = 10;

    printf("Global variable: %d\n", globV);
    printf("Local variable: %d\n", localV);

    fun(globV, localV);  /*calling function by passing global and local var*/
    
/*changing global variable and checking how it affects the same function call*/
    globV = 10;

    modifiedfun(globV, localV); /*calling function after changing global var*/

    return 0;
}

int fun(int a, int b){
    printf("Sum of global + local = %d\n", a + b);
}

int modifiedfun(int a, int b){
    printf("After changing global variable to %d in main fun, sum = %d\n", a, a + b);
}
