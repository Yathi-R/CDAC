#include <stdio.h>

// Define the bit-field structure
struct {
    unsigned int low : 3;   // 3 bits
    unsigned int mid : 5;   // 5 bits
    unsigned int high : 8;  // 8 bits
} fields;

int main() {
    // Set values
    fields.low = 3;   // 3 bits, range: 0-7
    fields.mid = 15;  // 5 bits, range: 0-31
    fields.high = 255; // 8 bits, range: 0-255

    // Print values
    printf("low: %u\n", fields.low);
    printf("mid: %u\n", fields.mid);
    printf("high: %u\n", fields.high);

    // Combine fields into a single unsigned int
    unsigned int combined = *(unsigned int*)&fields;

    // Print the combined value in hexadecimal format
    printf("Combined value: 0x%X\n", combined);

    return 0;
}