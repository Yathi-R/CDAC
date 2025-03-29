/*Write a C program that defines an enum Operation with values ADD, SUBTRACT,
MULTIPLY, and DIVIDE. Write a function performOperation that takes two integers
and an Operation enum value, performs the corresponding operation, and returns the
result. Demonstrate this function in your main function.*/

#include <stdio.h>

// Type defining an enum for operations
typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
} Operation;

// Function to perform the selected operation
float performOperation(int a, int b, Operation op) {

    switch (op) {

        case ADD:
            return a + b;

        case SUBTRACT:
            return a - b;

        case MULTIPLY:
            return a * b;

        case DIVIDE:
            if (b != 0)
                return (float)a / b;
            else {
                printf("Error: Division by zero!\n");
                return 0;
            }

        default:
            printf("Invalid operation!\n");
            return 0;
    }
}

int main() {

    int num1 = 10, num2 = 5;
    
    printf("num 1: %d and num2 : %d\n", num1, num2);
    
    //Fun calling and printing
    printf("Addition: %d\n", (int) performOperation(num1, num2, ADD));
    printf("Subtraction: %d\n", (int) performOperation(num1, num2, SUBTRACT));
    printf("Multiplication: %d\n", (int) performOperation(num1, num2, MULTIPLY));
    printf("Division: %0.2f\n", performOperation(num1, num2, DIVIDE));
    
    return 0;
}
