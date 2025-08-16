#include <stdio.h>

struct {
    unsigned int a : 1;
    unsigned b : 3;
    unsigned int c : 4;
} bitField;
int main() {
    printf("a: %d\n", bitField.a);
    printf("b: %d\n", bitField.b);
    printf("c: %d\n", bitField.c);
    
    bitField.a = 1;  // 1 bit, range: 0-1
    bitField.b = 5;  // 3 bits, range: 0-7
    bitField.c = 10; // 4 bits, range: 0-15

    printf("a: %d\n", bitField.a);
    printf("b: %d\n", bitField.b);
    printf("c: %d\n", bitField.c);

    unsigned int a = 0xF0F0; // 1111 0000 1111 0000 in binary
unsigned int b = 0x0F0F; // 0000 1111 0000 1111 in binary
unsigned int result = a | b; // 1111 1111 1111 1111 in binary
printf("Result of OR: 0x%X\n", result); // Output: 0xFFFF


    return 0;
}