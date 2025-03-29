#include <stdio.h>

// Define a mock hardware register using a volatile unsigned int
volatile unsigned int hardware_register = 0x00;

// Define bit positions for the flags
#define FLAG1 (1 << 0) // Bit 0
#define FLAG2 (1 << 1) // Bit 1
#define FLAG3 (1 << 2) // Bit 2
#define FLAG4 (1 << 3) // Bit 3

void setFlag(unsigned int flag) {
    hardware_register |= flag; // Set the flag
}

void clearFlag(unsigned int flag) {
    hardware_register &= ~flag; // Clear the flag
}

void toggleFlag(unsigned int flag) {
    hardware_register ^= flag; // Toggle the flag
}

int checkFlag(unsigned int flag) {
    return (hardware_register & flag) != 0; // Check if the flag is set
}

int main() {
    // Set FLAG1 and FLAG3
    setFlag(FLAG1);
    setFlag(FLAG3);
    
    // Print register value
    printf("Register after setting FLAG1 and FLAG3: 0x%02X\n", hardware_register);

    // Clear FLAG1
    clearFlag(FLAG1);
    
    // Print register value
    printf("Register after clearing FLAG1: 0x%02X\n", hardware_register);

    // Toggle FLAG2 and FLAG4
    toggleFlag(FLAG2);
    toggleFlag(FLAG4);
    
    // Print register value
    printf("Register after toggling FLAG2 and FLAG4: 0x%02X\n", hardware_register);

    // Check if FLAG3 is set
    if (checkFlag(FLAG3)) {
        printf("FLAG3 is set.\n");
    } else {
        printf("FLAG3 is not set.\n");
    }

    return 0;
}