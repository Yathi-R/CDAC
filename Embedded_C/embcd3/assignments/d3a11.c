/*Write a menu driven program to perform basic arithmetic operations.
Menu options – 0 to Exit, 1 to Add, 2 to Subtract, 3 to Multiply, 4 to Divide.
Depending upon the choice entered by user the arithmetic operations should be
performed and continue till user wants.*/

/*Menu driven program to perform arithmetic operation until user wants*/

#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    do {
        // Display menu
        printf("\n===== Arithmetic Operations Menu =====\n");
        printf("0. Exit\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Processing the choice
        if (choice >= 1 && choice <= 4) {

            // Getting two numbers from user
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (choice) {

            case 1:
                result = num1 + num2;
                printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4:
                if (num2 != 0) {

                    result = num1 / num2;
                    printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, result);
                } 
                
                else {
                    printf("\nDivision by zero is not allowed\n");
                }
                break;

            case 0:
                printf("\nExiting the program\n");
                break;

            default:
                printf("\nInvalid choice, please enter a valid option\n");
        }

    } while (choice != 0); // Loop continues until user chooses 0

return 0;
}
