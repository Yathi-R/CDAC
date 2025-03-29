/*Initializing & printing global and local varibale*/
#include<stdio.h>

int globV1 = 1000;

int main(){

    int localV1 = -100;

    printf("Global variable: %d\n", globV1);
    printf("Local variable: %d\n", localV1);

    return 0;
}