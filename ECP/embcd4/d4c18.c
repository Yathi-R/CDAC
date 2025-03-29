#include <stdio.h>

int main() {
    char str[100]; // Assuming maximum length of 100 characters
    int length = 0;

    // Getting string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Calculate the length without strlen function
    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    
    // Displaying the length of the string
    printf("Length of the string: %d\n", length);
    
    return 0;
}