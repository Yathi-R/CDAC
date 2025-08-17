/*Write a C program to print the multiplication table for a number up to 10 using nested
for loops. The number should be input by the user.*/

/*To print the multiplication table of a user given number up to 10
 using nested for loops*/

#include <stdio.h>

int main() {
    int num;

    // Taking user input
    printf("Enter the table number: ");
    scanf("%d", &num);

    // Outer loop
    for (int i = 1; i <= 10; i++) {
        
        // Inner loop
        for (int j = num; j <= num; j++) {
            printf("%d x %d = %d\n", j, i, j * i);
        }
    }

return 0;
}
