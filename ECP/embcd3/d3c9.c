/*To print numbers from 1 to 20 but skip div of 5 using continue*/

#include <stdio.h>

int main() {
    
    for (int i = 1; i <= 20; i++) {
        
        /* Skip numbers divisible by 5 */
        if (i % 5 == 0) {
            printf("Skipped\n");
            continue;  
        }
        /* Prints the number if it's not divisible by 5 */
        printf("%d\n", i);
    }

    return 0;
}
