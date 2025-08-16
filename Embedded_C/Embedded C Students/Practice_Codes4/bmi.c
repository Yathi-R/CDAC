#include <stdio.h>

int main() {
    float height, weight, bmi;

    // Input height in meters
    printf("Enter your height in meters: ");
    scanf("%f", &height);

    // Input weight in kilograms
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    // Calculate BMI
    bmi = weight / (height * height);

    // Display the BMI
    printf("Your BMI is: %.2f\n", bmi);

    // Optional: Display BMI category
    if (bmi < 18.5) {
        printf("Category: Underweight\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Category: Normal weight\n");
    } else if (bmi >= 25 && bmi < 29.9) {
        printf("Category: Overweight\n");
    } else {
        printf("Category: Obesity\n");
    }

    return 0;
}