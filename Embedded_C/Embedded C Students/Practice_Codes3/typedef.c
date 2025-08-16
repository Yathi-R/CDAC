#include <stdio.h>

typedef unsigned long ulong;

int main() {
    ulong a = 1000000000; // Initialize a with a large value
    ulong b = 2000000000; // Initialize b with another large value

    // Print the values
    printf("Value of a: %lu\n", a);
    printf("Value of b: %lu\n", b);

    // Perform arithmetic operations
    ulong sum = a + b;
    printf("Sum of a and b: %lu\n", sum);

    return 0;
}