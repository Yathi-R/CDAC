#include <stdio.h>
int factorial(int n);
int main() {
    int number = 7;
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}
int factorial(int n) {
    if (n == 0) {  // Base case
        return 1;
    } else {  // Recursive case
        return n * factorial(n - 1);
    }
}