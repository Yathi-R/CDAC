/*Write a C program to find the largest and smallest elements in an array of integers. The size
of the array and the elements should be input by the user.*/

/*Largest and smallest element in the array*/

#include <stdio.h>

// Function to find the largest element
int findLargest(int arr[], int size) {

    int largest = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) { // Finding the largest
            largest = arr[i];
        }
    }
    return largest;
}

// Function to find the smallest element
int findSmallest(int arr[], int size) {

    int smallest = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) { // Finding the smallest
            smallest = arr[i];
        }
    }
    return smallest;
}

int main() {

    int n;

    // Getting size of the array from the user
    printf("Enter the number of elements for the array: ");
    scanf("%d", &n);

    int numbers[n]; 

    // Getting the elements of the array
    printf("Enter the elements of the integer array:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Finding largest and smallest using functions
    int largest = findLargest(numbers, n);
    int smallest = findSmallest(numbers, n);

    printf("The largest number in the array is %d\n", largest);
    printf("The smallest number in the array is %d\n", smallest);

    return 0;
}
