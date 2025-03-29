/*Write a C program that defines an enum Operation with values ADD, SUBTRACT,
MULTIPLY, and DIVIDE. Write a function performOperation that takes two integers
and an Operation enum value, performs the corresponding operation, and returns the
result. Demonstrate this function in your main function. Take 2 integer values from
user.*/

#include <stdio.h>

// Define an enum for operations
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
            printf("Error: Division by zero!\n");
                return 0;

        default:
            printf("Invalid operation!\n");
            return 0;
    }
}

int main() {

    int num1, num2, choice;

    //Taking user input
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Choose operation (0-ADD, 1-SUBTRACT, 2-MULTIPLY, 3-DIVIDE): ");
    scanf("%d", &choice);

    // Validation the choice and calling fun to perform operation
    if (choice >= 0 && choice <= 3)
        printf("Result: %0.2f\n", performOperation(num1, num2, (Operation)choice)); //type casting choice to enum
    else
        printf("Invalid operation choice!\n");

    return 0;
}
