#include <stdio.h>
int main() {
    unsigned char flags = 0b10101010; // Binary representation: 10101010
    // Set the 2nd bit (0-based index)
    flags |= (1 << 2); // Binary: 10101110
    // Clear the 4th bit
    flags &= ~(1 << 4); // Binary: 10100110
    // Toggle the 6th bit
    flags ^= (1 << 6); // Binary: 11100110

    printf("Flags: 0x%X\n", flags); // Output: Flags: 0xEE
    return 0;
}