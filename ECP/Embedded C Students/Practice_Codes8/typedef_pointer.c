#include <stdio.h>
typedef int* IntPtr;

int main() {
    IntPtr ptr;
    int value = 5;
    ptr = &value;

    printf("Value: %d\n", *ptr);  // Output: Value: 5
    return 0;
}