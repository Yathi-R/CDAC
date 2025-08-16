#include <stdio.h>
void increment(int *p) {
    (*p)++;  // Increment the value pointed to by p
}
int main() {
    int num = 10;
    increment(&num);  // Pass address of num to the function
    printf("Incremented value: %d\n", num);  // Output: 11
    return 0;
}