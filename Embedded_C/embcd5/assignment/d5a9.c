/*Function and pointer*/
/*To access elements of an array of 10 elements using pointer arithmetic*/

#include <stdio.h>

// Function to take 10 input for the array using pointer
void inputArray(int *ptr, int size) {

    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", (ptr + i));  // Using pointer arithmetic to store values
    }
}

// Function to print array of 10 elements using pointer arithmetic
void printArray(int *ptr, int size) {

    printf("\nArray elements using pointer arithmetic:\n");

    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));  // Accessing elements using pointer
    }
}

int main() {

    int arr[10];

    // Function calls to get and display array elements
    inputArray(arr, 10);
    printArray(arr, 10);

    return 0;
}
