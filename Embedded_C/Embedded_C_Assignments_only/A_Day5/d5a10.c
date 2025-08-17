/*Write a C program to perform concatenation on 2 strings. Use pointers to string for
strcat() function.*/

#include <stdio.h>

// Function to concatenate two strings using pointers
void myStrcat(char *dest, char *src) {

    // Moving pointer to the end of dest string
    while (*dest != '\0') {
        dest++;
    }

    // Copying characters from src to dest
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    // Null-terminate the concatenated string
    *dest = '\0';
}

int main() {

    char str1[100], str2[50];

    // Taking input from user
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Removing newline character from fgets()
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '\n') {
            str1[i] = '\0';
            break;
        }
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == '\n') {
            str2[i] = '\0';
            break;
        }
    }

    // Concatenating strings using pointer function
    myStrcat(str1, str2);

    printf("\nConcatenated String: %s\n", str1);

    return 0;
}
