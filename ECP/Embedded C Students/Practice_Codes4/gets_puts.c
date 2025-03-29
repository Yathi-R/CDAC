#include <stdio.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Reads a line of text
    printf("You entered: ");
    puts(str);  // Prints the string followed by a newline
    return 0;
}