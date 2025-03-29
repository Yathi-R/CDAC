#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30};
    int *ptr = arr;  // Equivalent to &arr[0]

    printf("First element: %d\n", *ptr);
    printf("Second element: %d\n", *(ptr + 1));
    printf("Third element: %d\n", *(ptr + 2));

    return 0;
}