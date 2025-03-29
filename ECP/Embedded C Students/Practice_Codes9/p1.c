#include <stdio.h> 
#define MAX_LENGTH 100 // Define the maximum length of the input string 
int main() { 
char str[MAX_LENGTH];			 // Array to hold the input string 
int index = 0;						 // Index for the array 
char ch; 							// Variable to hold each character read 
printf("Enter a string: "); 			// Read characters until newline or maximum length is reached 
while ((ch = getchar()) != '\n' && index < MAX_LENGTH - 1) {
	str[index++] = ch; 			// Store character in the array and increment index 
} 
str[index] = '\0'; // Null-terminate the string 
printf("You entered: %s\n", str);	
return 0; 
}