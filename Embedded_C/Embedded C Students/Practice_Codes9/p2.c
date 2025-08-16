#include <stdio.h>

struct BitField {
    unsigned int low : 8;  // 8 bits for 'low'
    unsigned int mid : 8;  // 8 bits for 'mid'
    unsigned int high : 16; // 16 bits for 'high'
};

int main() {
    // Define and initialize a BitField structure
    struct BitField bitField;
    bitField.low = 0x12;    // Example value for low
    bitField.mid = 0x34;    // Example value for mid
    bitField.high = 0x5678; // Example value for high

    // Print values of low, mid, and high
    printf("low: 0x%X\n", bitField.low);
    printf("mid: 0x%X\n", bitField.mid);
    printf("high: 0x%X\n", bitField.high);

    // Combine fields into a single unsigned int
    unsigned int combined = (bitField.high << 16) | (bitField.mid << 8) | bitField.low;

    // Print the combined value in hexadecimal
    printf("Combined value: 0x%X\n", combined);

    return 0;
}