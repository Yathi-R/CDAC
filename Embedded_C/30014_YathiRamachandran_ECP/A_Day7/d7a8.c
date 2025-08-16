/*In embedded systems, you often need to control specific bits in a hardware register to enable or
disable features. Write a C program to use bitwise operators to set, clear, and toggle flags in a
register.*/

#include <stdio.h>

// Define the register (for example, a 16-bit register)
typedef unsigned short uInt;

// Function to set a bit at a given position
void set_bit(uInt *reg, uInt bit_position) {

    *reg |= (1 << bit_position);  // Set the bit at the given position to 1
}

// Function to clear a bit at a given position
void clear_bit(uInt *reg, uInt bit_position) {

    *reg &= ~(1 << bit_position);  // Clear the bit at the given position to 0
}

// Function to toggle a bit at a given position
void toggle_bit(uInt *reg, uInt bit_position) {

    *reg ^= (1 << bit_position);  // Toggle the bit at the given position
}

// Function to print the 16-bit register value in binary format
void print_register(uInt reg) {

    for (int i = 15; i >= 0; i--) {
        printf("%d", (reg >> i) & 1);
        if (i % 4 == 0) {  // Adding space after every 4 bits for better readability
            printf(" ");
        }  
    }
    printf("\n");
}

int main() {

    uInt register_value = 0x00;  // Initialize register with 0x00 (all bits are 0)

    printf("Initial register value: ");
    print_register(register_value);

    // Set bit at position 3
    set_bit(&register_value, 3);
    printf("After setting bit 3: ");
    print_register(register_value);

    // Clear bit at position 3
    clear_bit(&register_value, 3);
    printf("After clearing bit 3: ");
    print_register(register_value);

    // Toggle bit at position 5
    toggle_bit(&register_value, 5);
    printf("After toggling bit 5: ");
    print_register(register_value);

    // Toggle bit at position 5 again (this will flip the bit back to the original state)
    toggle_bit(&register_value, 5);
    printf("After toggling bit 5 again: ");
    print_register(register_value);

    return 0;
}
