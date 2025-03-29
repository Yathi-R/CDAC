/*Write a C program to calculate the average of n integers stored in an array. The size of the
array and the elements should be provided by the user.*/

/*Average of n element in the array*/

#include <stdio.h>

// Function to get input for the array
void inputArray(int arr[], int size) {

    printf("Enter the elements of the integer array:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to calculate the sum of array elements
int calculateSum(int arr[], int size) {

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average
float calculateAverage(int sum, int size) {
    return (float) sum / size;
}

int main() {

    int n;

    // Getting size of the array from the user
    printf("Enter the number of elements for the array: ");
    scanf("%d", &n);

    int numbers[n];

    // Fun to get array input
    inputArray(numbers, n);

    // Calculating sum
    int sum = calculateSum(numbers, n);

    // Calculating average
    float average = calculateAverage(sum, n);

    printf("The Average of the %d elements in the array is %.2f\n", n, average);

    return 0;
}
