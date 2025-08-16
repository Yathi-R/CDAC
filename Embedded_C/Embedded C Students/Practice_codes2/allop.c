#include <stdio.h>
int main() {
    int a = 10, b = 20;
    int result;
    // Arithmetic Operators
    result = a + b;
    printf("Addition: %d\n", result);  // Addition: 30
    result = b - a;
    printf("Subtraction: %d\n", result);  // Subtraction: 10
    result = a * b;
    printf("Multiplication: %d\n", result);  // Multiplication: 200
    result = b / a;
    printf("Division: %d\n", result);  // Division: 2
    result = b % a;
    printf("Modulus: %d\n", result);  // Modulus: 0
// Relational Operators
    printf("Equal to: %d\n", (a == b));  // Equal to: 0
    printf("Not equal to: %d\n", (a != b));  // Not equal to: 1
    printf("Greater than: %d\n", (a > b));  // Greater than: 0
    printf("Less than: %d\n", (a < b));  // Less than: 1
    printf("Greater than or equal to: %d\n", (a >= b));  // Greater than or equal to: 0
    printf("Less than or equal to: %d\n", (a <= b));  // Less than or equal to: 1

    // Logical Operators
    printf("Logical AND: %d\n", (a && b));  // Logical AND: 1
    printf("Logical OR: %d\n", (a || b));  // Logical OR: 1
    printf("Logical NOT: %d\n", (!a));  // Logical NOT: 0
// Bitwise Operators

    result = a & b;
    printf("Bitwise AND: %d\n", result);  // Bitwise AND: 0
    result = a | b;
    printf("Bitwise OR: %d\n", result);  // Bitwise OR: 30
    result = a ^ b;
    printf("Bitwise XOR: %d\n", result);  // Bitwise XOR: 30
    result = ~a;
    printf("Bitwise NOT: %d\n", result);  // Bitwise NOT: -11
    result = a << 1;
    printf("Left shift: %d\n", result);  // Left shift: 20
    result = a >> 1;
    printf("Right shift: %d\n", result);  // Right shift: 5
// Assignment Operators

    a += 5;
    printf("Add and assign: %d\n", a);  // Add and assign: 15
    a -= 3;
    printf("Subtract and assign: %d\n", a);  // Subtract and assign: 12
    a *= 2;
    printf("Multiply and assign: %d\n", a);  // Multiply and assign: 24
    a /= 4;
    printf("Divide and assign: %d\n", a);  // Divide and assign: 6
    a %= 3;
    printf("Modulus and assign: %d\n", a);  // Modulus and assign: 0
// Unary Operators

    a = -a;
    printf("Unary minus: %d\n", a);  // Unary minus: 0
    a++;
    printf("Increment: %d\n", a);  // Increment: 1
    a--;
    printf("Decrement: %d\n", a);  // Decrement: 0
    int *ptr = &a;
    printf("Address-of: %p\n", ptr);  // Address-of: (address of a)
    int value = *ptr;
    printf("Dereference: %d\n", value);  // Dereference: 0
    int size = sizeof(a);
    printf("Sizeof: %d\n", size);  // Sizeof: 4 (on most systems)
// Ternary Operator
    result = (a > b) ? a : b;
    printf("Ternary operator: %d\n", result);  // Ternary operator: 20

// Comma Operator
    result = (a = 1, b = 2, a + b);
    printf("Comma operator: %d\n", result);  // Comma operator: 3

// Typecast Operator
    float f = (float)a;
    printf("Typecast operator: %f\n", f);  // Typecast operator: 1.000000

    return 0;
}
