/*Define a Bit-Field Structure with fields for low, mid, and high. Set Values for these fields.
Print Values of low, mid, and high. Combine Fields into a single unsigned int and print its
hexadecimal representation.*/


#include <stdio.h>

typedef unsigned int uInt;

// Define the Bit-Field structure
typedef struct {
    uInt low : 8;  // 8 bits for the 'low' field
    uInt mid : 8;  // 8 bits for the 'mid' field
    uInt high : 8; // 8 bits for the 'high' field
} BitField;

int main() {

    // Create an instance of BitField
    BitField bf;

    // Setting values for the fields
    bf.low = 0xF0;    // Low field: 8 bits (0xF0)
    bf.mid = 0xA5;    // Mid field: 8 bits (0xA5)
    bf.high = 0x1C;   // High field: 8 bits (0x1C)

    // Print the individual values of low, mid, and high
    printf("Low: 0x%X\n", bf.low);
    printf("Mid: 0x%X\n", bf.mid);
    printf("High: 0x%X\n", bf.high);

    // Combine the fields into a single unsigned int
    uInt combined = (bf.high << 16) | (bf.mid << 8) | bf.low;

    // Print the combined value in hexadecimal
    printf("Combined value: 0x%X\n", combined);

    return 0;
}
