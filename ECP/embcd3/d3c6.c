/*Basic Calculator using if/ elif conditions*/

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

    /*Performing arithmetic operations using if/else if/else*/
    if (op == '+'){
        printf("Sum of %d and %d = %d\n", num1, num2, num1+num2);
    }
    else if (op =='-'){
        printf("Subtraction of %d and %d = %d\n", num1, num2, num1-num2);
    }
    else if (op =='*'){
        printf("Multiplication of %d and %d = %d\n", num1, num2, num1*num2);
    }
    else if (op =='/'){
        if (num2 != 0){ 
            printf("Integer Division of %d and %d = %d\n", num1, num2, num1/num2);
            }
          else{
            printf("Can't divide by 0\n");
          } 
    }
    else {
        printf("Invalid operator, enter only (+, -, *, /)\n");
    }


return 0;
}