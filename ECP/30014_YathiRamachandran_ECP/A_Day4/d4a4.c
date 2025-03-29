/*Write a C program to reverse the elements of an array. The size of the array and the elements
should be provided by the user.*/

/*Print elements of arrays in reverse*/

#include <stdio.h>

// Function to get array input from user
void inputArray(int arr[], int size) {

    printf("Enter the elements of integer array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(int arr[], int size, char message[]) {

    printf("\n%s\n", message);
    for (int i = 0; i < size; i++) {
        printf("Number at %d position in the array is %d\n", i, arr[i]);
    }
}

// Function to reverse the array
void reverseArray(int arr[], int size) {

    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];    
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    
    int n;

    // Getting the size of the array
    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n];

    // Getting array input from user
    inputArray(numbers, n);

    // Displaying the elements of array before reversing
    displayArray(numbers, n, "Printing the elements of array before reversing:");

    // Reversing the array
    reverseArray(numbers, n);

    // Displaying the reversed array
    displayArray(numbers, n, "Printing the elements of reversed array:");
    
    return 0;
}
