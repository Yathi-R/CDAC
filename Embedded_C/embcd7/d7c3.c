#include<stdio.h>


float calculator (int a, int b, char op){
    switch (op){
        case '+':
            return a+b;

        case '-':
            return a-b;
        
        case '*':
            return a*b;
        
        case '/':
            if (b != 0){
                return (float)a/b;
            }else {
                printf("Can't divide by 0\n");
                return 0;
            }
        
        default :
            printf("Invalid Operation\n");
            return 0;
    }
}

void displayResult(float (*func_ptr)(int, int, char), int num1, int num2, char op){
    
    printf("Result: %0.2f\n", func_ptr(num1, num2, op));
} 


int main(){

    int num1, num2;
    char op;
    
    printf("Enter 2 number: ");
    scanf("%d%d", &num1, &num2);

    getchar();

    printf("Enter the arithmetic Operator (+, -, *, /):");
    scanf("%c", &op);

    displayResult(calculator, num1, num2, op);

return 0;
}