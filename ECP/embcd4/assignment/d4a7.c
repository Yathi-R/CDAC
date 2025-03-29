/*Write a C program to get a person’s height and weight and calculate their BMI.*/

/* Program to calculate BMI*/

#include <stdio.h>

// Function to get the name of the user
void getName(char name[]) {

    printf("Enter your name: ");
    fgets(name, 30, stdin);
}

// Function to get the height of the user
float getHeight() {

    float height;
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    return height;
}

// Function to get the weight of the user
float getWeight() {

    float weight;
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    return weight;
}

// Function to validate the height and weight input
int validateInput(float height, float weight) {

    if (height <= 0 || weight <= 0) {
        printf("Invalid height or weight\n");
        return 0;  // Return 0 for invalid input
    }
    return 1;  // Return 1 for valid input
}

// Function to calculate BMI
float calculateBMI(float height, float weight) {
    return weight / (height * height);
}

// Function to display the BMI and its category
void displayBMIResult(char name[], float bmi) {

    printf("Hello %sYour BMI is %.2f\n", name, bmi);

    // Displaying BMI classification
    if (bmi >= 28.5) {
        printf("Your BMI indicates you are \"Obese\".\n");
    } 
    else if (bmi <= 18.5) {
        printf("Your BMI indicates you are \"Underweight\".\n");
    } 
    else if (bmi >= 25 && bmi < 28.5) {
        printf("Your BMI indicates you are \"Overweight\".\n");
    } 
    else {
        printf("Your BMI is in the \"Normal range\".\n");
    }
}

int main() {

    char name[30];
    float height, weight, bmi;

    // Getting user details
    getName(name);
    height = getHeight();
    weight = getWeight();

    // Input validation
    if (!validateInput(height, weight)) {
        return 1;
    }

    // Calculating BMI
    bmi = calculateBMI(height, weight);

    // Displaying result
    displayBMIResult(name, bmi);

    return 0;
}
