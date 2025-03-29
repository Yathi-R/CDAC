#include <stdio.h>
#define PI 3.14159          // Symbolic constant

int main() {
    // Integer constants
    int decimal = 123;      // Decimal constant
    int octal = 0173;       // Octal constant
    int hex = 0x7B;         // Hexadecimal constant

    // Floating-point constants
    float floatNum = 123.45f;
    double doubleNum = 123.45;
    long double longDoubleNum = 123.45L;

    // Character constants
    char char1 = 'A';
    char newline = '\n';
    char tab = '\t';
    
    // String constants
    char str1[] = "Hello, World!";
    char str2[] = "C programming";
    
    // Constant variables
    const int MAX = 100;

// Printing constants
    printf("Integer Constants: %d, %d, %d\n", decimal, octal, hex);
    printf("Floating-point Constants: %f, %lf, %Lf\n", floatNum, doubleNum, longDoubleNum);
    printf("Character Constants: %c, %c, %c\n", char1, tab, newline, tab, newline, tab);
    printf("String Constants: %s, %s\n", str1, str2);
    printf("Symbolic Constant PI: %f\n", PI);
    printf("Constant Variable MAX: %d\n", MAX);
    return 0;
}
