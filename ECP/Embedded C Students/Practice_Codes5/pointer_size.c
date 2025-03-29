#include <stdio.h>

int main() {
    printf("Size of int pointer: %zu bytes\n", sizeof(int *));
    printf("Size of char pointer: %zu bytes\n", sizeof(char *));
    printf("Size of double pointer: %zu bytes\n", sizeof(double *));
    return 0;
}