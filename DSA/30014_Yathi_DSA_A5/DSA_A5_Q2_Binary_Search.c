#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid;
        }
        // If key is greater, ignore left half
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}

int main() {
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array (in sorted order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element %d found at position %d\n", key, result + 1);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
