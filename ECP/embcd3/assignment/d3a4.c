/*calculating the sum of the first n +ve integers using a for loop*/

#include <stdio.h>

int main() {

    int n, sum;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Checking if the input is a positive integer
    if (n > 0) {

        // Calculating the sum using a for loop
        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        printf("The sum of the first %d positive integers is: %d\n", n, sum);
    }

    else {
        printf("Enter a positive integer greater than 0 \n");
    }

return 0;
}
