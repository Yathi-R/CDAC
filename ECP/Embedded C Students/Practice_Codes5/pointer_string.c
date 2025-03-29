#include <stdio.h>
void printString(char *str) {
    while (*str) {
        putchar(*str);
        str++;
    }
    putchar('\n');
}

int main() {
    char myStr[] = "Hello, World!";
    printString(myStr);  // Pass the string to the function
    return 0;
}