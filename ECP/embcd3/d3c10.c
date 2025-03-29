/*Program to demonstrate break, return and goto in loops*/

#include <stdio.h>

int main() {
    int i;

    /* Using break in for loop */
    printf("Using break:\n");

    for (i = 1; i <= 10; i++) {
        
        // Exit the loop when i = 5
        if (i == 5) {

            printf("Breaking the loop when i = %d\n", i);
            break;  
        }
        printf("i = %d\n", i);
    }

    // Using goto inside a loop
    printf("\nUsing goto:\n");

    for (i = 1; i <= 10; i++) {
        
        // Jump to 'yathi'
        if (i == 3) {
            
            printf("Jumping when i = %d\n", i);
            goto yathi;  
        }
        printf("i = %d\n", i);
    }

    yathi: printf("The loop jumped to here\n");

    // Using return inside a loop
    printf("\nUsing return:\n");

    for (i = 1; i <= 10; i++) {
        
        // Ends program when i is 7
        if (i == 7) {

            printf("Returning from the loop when i = %d\n", i);
            return 1;  
        }
        printf("i = %d\n", i);
    }

    
return 0;
}
