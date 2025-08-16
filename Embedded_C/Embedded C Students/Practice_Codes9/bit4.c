#include <stdio.h>

// Define a bit-field structure
struct {
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 4;
} bitField;

int main() {
    // Initialize bit-field values
    bitField.a = 1;  // 1 bit, range: 0-1
    bitField.b = 5;  // 3 bits, range: 0-7
    bitField.c = 10; // 4 bits, range: 0-15

    // Print initial values
    printf("Initial values:\n");
    printf("a: %d\n", bitField.a);
    printf("b: %d\n", bitField.b);
    printf("c: %d\n", bitField.c);

    // Perform bitwise operations
    unsigned int value = *(unsigned int*)&bitField; // Treat bitField as an unsigned integer
    printf("Value is: 0x%X\n", value);

    // Bitwise AND
    unsigned int andResult = value & 0x0F; // Mask with 00001111 to keep the last 4 bits
    printf("AND result: 0x%X\n", andResult);

    // Bitwise OR
    unsigned int orResult = value | 0x20; // Set the 6th bit (0x20 is 00100000 in binary)
    printf("OR result: 0x%X\n", orResult);

    // Bitwise XOR
    unsigned int xorResult = value ^ 0xF0; // Toggle the upper 4 bits (0xF0 is 11110000 in binary)
    printf("XOR result: 0x%X\n", xorResult);

    // Bitwise NOT
    unsigned int notResult = ~value; // Invert all bits
    printf("NOT result: 0x%X\n", notResult);

    // Bitwise Shift Left
    unsigned int shiftLeftResult = value << 2; // Shift left by 2 bits
    printf("Shift Left result: 0x%X\n", shiftLeftResult);

    // Bitwise Shift Right
    unsigned int shiftRightResult = value >> 2; // Shift right by 2 bits
    printf("Shift Right result: 0x%X\n", shiftRightResult);

    return 0;
}