#include <stdio.h>

// Define the bit-field structure
struct {
    unsigned int low : 4;    // 4 bits
    unsigned int mid : 6;    // 6 bits
    unsigned int high : 8;   // 8 bits
} fields;

int main() {
    // Set values
    fields.low = 7;    // 4 bits, range: 0-15
    fields.mid = 32;   // 6 bits, range: 0-63
    fields.high = 200; // 8 bits, range: 0-255

    // Combine fields into a single unsigned int for bitwise operations
    unsigned int combined = *(unsigned int*)&fields;

    // Print the original combined value
    printf("Original combined value: 0x%X\n", combined);

    // Perform bitwise left shift operation by 3 bits
    unsigned int leftShiftResult = combined << 3;
    printf("Result after left shift by 3 bits: 0x%X\n", leftShiftResult);

    // Perform bitwise right shift operation by 2 bits
    unsigned int rightShiftResult = combined >> 2;
    printf("Result after right shift by 2 bits: 0x%X\n", rightShiftResult);

    return 0;
}