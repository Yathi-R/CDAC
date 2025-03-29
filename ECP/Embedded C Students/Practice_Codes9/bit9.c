#include <stdio.h>

#define MASK_LOW  0x0F // Mask to isolate the lower 4 bits
#define MASK_HIGH 0xF0 // Mask to isolate the higher 4 bits

void applyMask(unsigned int value, unsigned int mask) {
    unsigned int result = value & mask; // Apply the mask using bitwise AND
    printf("Result after applying mask 0x%02X: 0x%02X\n", mask, result);
}

void setMask(unsigned int *value, unsigned int mask) {
    *value |= mask; // Set bits specified by the mask
}

void clearMask(unsigned int *value, unsigned int mask) {
    *value &= ~mask; // Clear bits specified by the mask
}

int main() {
    unsigned int value = 0xAB; // Example value: 10101011 in binary

    // Apply MASK_LOW to isolate lower 4 bits
    applyMask(value, MASK_LOW);
    
    // Apply MASK_HIGH to isolate higher 4 bits
    applyMask(value, MASK_HIGH);

    // Set bits using MASK_LOW
    setMask(&value, MASK_LOW);
    printf("Value after setting MASK_LOW: 0x%02X\n", value);

    // Clear bits using MASK_HIGH
    clearMask(&value, MASK_HIGH);
    printf("Value after clearing MASK_HIGH: 0x%02X\n", value);

    return 0;
}