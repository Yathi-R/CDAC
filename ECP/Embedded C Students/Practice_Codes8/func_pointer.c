#include <stdio.h>
typedef int (*FuncPtr)(int, int);
int add(int a, int b) {
    return a + b;
}

int main() {
    FuncPtr ptr = add;
    printf("Sum: %d\n", ptr(5, 3));  // Output: Sum: 8
    return 0;
}