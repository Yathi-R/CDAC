#include <stdio.h>

// Define the bit-field structure
struct {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int reserved : 3;
} flags;

int main() {
    // Initialize bit-field values
    flags.bit0 = 1;
    flags.bit1 = 0;
    flags.bit2 = 1;
    flags.bit3 = 1;
    flags.bit4 = 0;

    // Combine bit-fields into an integer for bitwise operations
    unsigned int combined = *(unsigned int*)&flags;

    // Define the mask for bitwise operations
    unsigned int mask = 0xF;  // 00001111 in binary

    // Perform bitwise AND operation
    unsigned int andResult = combined & mask;
    printf("Bitwise AND result with 0xF: 0x%X\n", andResult);

    // Perform bitwise OR operation
    unsigned int orResult = combined | mask;
    printf("Bitwise OR result with 0xF: 0x%X\n", orResult);

    // Perform bitwise XOR operation
    unsigned int xorResult = combined ^ mask;
    printf("Bitwise XOR result with 0xF: 0x%X\n", xorResult);

    return 0;
}