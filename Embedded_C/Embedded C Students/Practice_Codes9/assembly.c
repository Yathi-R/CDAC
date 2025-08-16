#include <stdio.h>
int main() {
    int result;
    asm("movl $5, %%eax;"
        "movl $3, %%ebx;"
        "addl %%ebx, %%eax;"
        "movl %%eax, %0;"
        : "=r" (result)       // Output operand
        :                     // Input operands (none)
        : "%eax", "%ebx"      // Clobbered registers
    );
    printf("Result: %d\n", result); // Output: Result: 8
    return 0;
}