/*Write a C program to get a string from user through keyboard using getchar function.*/

#include <stdio.h>

// Function to read string from user through keyboard using getchar
void readinput(char *str, int size){

    char ch;
    int i = 0;

    printf("Enter the string: \n(press enter to end)\n");

    // using getchar to read the input
    while ( i < size - 1 && (ch = getchar()) != '\n' && ch != EOF) {
      
        *(str + i) = ch;
        i++;
    }
    *(str + i) = '\0';
    
}

int main() {

    char str[100];
    readinput(str, 100); //fun call to read the string

    printf("\n%s\n",str); //printing the string

    return 0;
}