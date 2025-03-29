/*Write a C program with static local variable named counter which should count from 1
to 5.*/

/*Static local variable to count from 1 to 5*/

#include<stdio.h>

//function prototype
int fun();

int main(){

    //calling function 5 times to count from 1 to 5
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    
    return 0;
}

//function using static local var counter 
int fun(){
    
    static int counter = 0;
    counter++;
    
    return counter;
}


