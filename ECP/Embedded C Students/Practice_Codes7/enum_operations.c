#include <stdio.h>

typedef enum {
    ADD, SUBTRACT, MULTIPLY, DIVIDE
} Operation;

int performOperation(int a, int b, Operation op) {
    switch (op) {
        case ADD: return a + b;
        case SUBTRACT: return a - b;
        case MULTIPLY: return a * b;
        case DIVIDE: return (b != 0) ? a / b : 0; // Avoid division by zero
        default: return 0;
    }
}

int main() {
    int x = 10, y = 5;
    printf("Sum: %d\n", performOperation(x, y, ADD));
    printf("Difference: %d\n", performOperation(x, y, SUBTRACT));
    printf("Product: %d\n", performOperation(x, y, MULTIPLY));
    printf("Quotient: %d\n", performOperation(x, y, DIVIDE));
    return 0;
}