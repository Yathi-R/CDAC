#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(void)
{
    char *str;
    char *ptr;
    int ch;
    int i = 0;

    // Allocate memory for the string
    str = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    ptr = str;  // Pointer to traverse and store characters

    printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);

    // Read characters until newline or maximum length is reached
    while ((ch = getchar()) != '\n' && i < MAX_LENGTH - 1) {
        *ptr++ = (char)ch;  // Store the character and move the pointer
        i++;
    }
    *ptr = '\0';  // Null-terminate the string

    printf("You entered: %s\n", str);

    // Free the allocated memory
    free(str);

    return 0;
}