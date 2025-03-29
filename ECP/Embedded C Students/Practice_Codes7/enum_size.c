#include <stdio.h>

enum Size { Small = 1, Medium, Large };

int main() {
    enum Size s = Large;
    printf("Value of enum is: %zu \n", s);
    printf("Size of enum Size: %zu bytes\n", sizeof(s));  // Output: Size of enum Size: 4 bytes (or platform-specific)

    return 0;
}