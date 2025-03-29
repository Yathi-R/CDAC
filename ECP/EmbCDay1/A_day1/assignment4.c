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

    fun(globV, localV);  /*calling function by passing 2 global and local var*/
    
/*changing global variable and checking how it affects the same function call*/
    globV = 10;

    modifiedfun(globV, localV); /*calling function after changing global var*/

return 0;
}

int fun(int a, int b){
    printf("Sum of global + local = %d\n", a+b);
}

int modifiedfun(int a, int b){
    printf("After changing global variable to %d in main fun, sum = %d\n", a, a+b);
}
