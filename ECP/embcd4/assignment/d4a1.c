/*Write a C program to input two numbers from user and add them. Use different functions for
different functionalities.*/

/*Different functions for getting 2 numbers from user and adding them*/

#include<stdio.h>

// function definition
void getnumbers();
void addnumbers();
void displaynumbers();

//declaring global variables
int num1, num2, sum;

int main(){

    //function calling for different functionalities
    getnumbers();
    addnumbers();
    displaynumbers();

    return 0;
}

//getting 2 numbers from user using function
void getnumbers(){

    //getting 2 numbers from user
    printf("Enter 2 numbers:");
    scanf("%d%d", &num1, &num2);
    
}

// adding 2 numbers using function
void addnumbers(){
    sum = num1 + num2;
}

//displaying sum using function
void displaynumbers(){
    printf("The sum of %d and %d = %d\n", num1, num2, sum);
}



