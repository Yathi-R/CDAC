#include <stdio.h>

int main(void) {
    int num1, num2, num3, num4, num5;

    // Prompt the user to enter 5 integers

    printf("Enter 5 integers:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);
    printf("Number 3: ");
    scanf("%d", &num3);
    printf("Number 4: ");
    scanf("%d", &num4);
    printf("Number 5: ");
    scanf("%d", &num5);

    // Print the integers in a single row
    
    printf("\nIntegers in a single row:\n");
    printf("%d %d %d %d %d\n", num1, num2, num3, num4, num5);

    // Print the integers each on a new line

    printf("Integers in different rows:\n");
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);

    return 0;
}