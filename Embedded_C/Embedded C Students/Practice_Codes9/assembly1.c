#include <stdio.h>
#include <x86intrin.h> // Header for GCC intrinsics
int main() {
    int a = 5, b = 3;
    int result = _addcarry_u32(0, a, b, &result); // Adds a and b with carry-in

    printf("Result: %d\n", result); // Output: Result: 8
    return 0;
}