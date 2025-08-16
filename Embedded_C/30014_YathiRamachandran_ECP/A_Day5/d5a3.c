/*Write a C program to calculate power of given base and index (power = base^index).*/

/*Program to calculate power of given base and index*/

#include <stdio.h>

// Function to calculate power using pointers
void calculatePower(double *base, int *index, double *result) {

    *result = 1;  

    // Handling negative exponent case
    int exp = *index < 0 ? -(*index) : *index;  

    // Multipling base by 'index' times
    for (int i = 0; i < exp; i++) {
        *result *= *base;
    }

    // If index is negative, take reciprocal
    if (*index < 0) {
        *result = 1 / *result;
    }
}

int main() {

    double base, result;
    int index;

    // Taking input from user
    printf("Enter base: ");
    scanf("%lf", &base);

    printf("Enter index (exponent): ");
    scanf("%d", &index);

    // Fun call (passing addresses of variables)
    calculatePower(&base, &index, &result);

    // Printing result
    printf("%.2lf^%d = %.6lf\n", base, index, result);

    return 0;
}
