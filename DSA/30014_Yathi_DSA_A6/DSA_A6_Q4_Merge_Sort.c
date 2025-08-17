//Implement Merge sort
#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub + 1];  
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int p = lb; p <= ub; p++) {
        arr[p] = b[p];
    }
}

void mergesort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);  
    }
}

void printArray(int arr[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int main() {

    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    if(n<2) return 0;

    mergesort(arr, 0, n - 1);
    
    printf("Sorted by Merge sort: ");
    printArray(arr, n);

    return 0;
}
