// Write a C program to find the largest and smallest elements in an array of integers. The size of the array and the elements should be input by the user.

#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}