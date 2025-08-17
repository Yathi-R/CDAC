//Selection sort algorithm to perform assending order sorting of Array

#include<stdio.h>

#define max_size 100 

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_index != i) {
            int temp1 = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp1;
        }
    }
}

// Function to print the array
void display(int a[], int size){
    for (int i = 0; i< size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main(){

    int size;
    printf("Enter the size of array (1 to 100): \n");
    scanf("%d", &size);

    if (size > max_size ){
        perror("Size of the array is larger\n");
        return 1;
    }
    int arr[size];

    for (int i = 0; i< size; i++){
        printf("Enter %d element", i+1);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    printf("Original array:\n");
    display(arr, size);

    selectionSort(arr, size);

    printf("Sorted array:\n");
    display(arr, size);

    return 0;
}
    
