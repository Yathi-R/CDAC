/*Write a C program to input data like: num1, num2 and arithmetic operation from user
and perform the task.*/

/*Taking input data like 2 numbers and arithmetic operator from user and performing the task*/

#include<stdio.h>

int main(){
    char op;
    int num1, num2;

    /*to get operator and operands from user*/
    printf("Enter the first number:");
    scanf("%d", &num1);

    printf("Enter the operator (+, -, *, / only):");
    scanf(" %c", &op);

    printf("Enter the second number:");
    scanf("%d", &num2);

    /*Performing arithmetic operation using switch*/
    switch (op)
    {
    case '+': printf("Sum of %d and %d = %d\n", num1, num2, num1+num2);
        break;
    
    case '-': printf("Subtraction of %d and %d = %d\n", num1, num2, num1-num2);
        break;
    
    case '*': printf("Multiplication of %d and %d = %d\n", num1, num2, num1*num2);
        break;
    
    case '/': if(num2 != 0){ 
                printf("Integer Division of %d and %d = %d\n", num1, num2, num1/num2);
                }
              else{
                printf("Can't divide by 0\n");
              } 
        break;
    default: printf("Invalid operator, enter only (+, -, *, /)\n");
        break;
    }

return 0;
}