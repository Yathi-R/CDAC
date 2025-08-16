/*Write a C program to find the length of a given string without using the strlen function. The
string should be input by the user.*/

/*Calculating the length of the user given string without strlen function*/

#include <stdio.h>

// Function to get the string from the user
void getString(char str[], int size) {

    printf("Enter a string: ");
    fgets(str, size, stdin);
}

// Function to calculate the length of the string without strlen()
int calculateLength(char str[], int size) {

    int length = 0;

    while (length < size && str[length] != '\0' && str[length] != '\n') {
        length++;
    }

    return length;
}

// Function to display the length of the string
void displayLength(int length) {

    printf("Length of the string: %d\n", length);
}

int main() {
    
    char str[100];
    int length;

    // Getting string from user
    getString(str, 100);

    // Calculating length of string
    length = calculateLength(str, 100);

    // Displaying the length of the string
    displayLength(length);

    return 0;
}
