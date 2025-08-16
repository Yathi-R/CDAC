#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[3];

    printf("Difference between ptr2 and ptr1: %ld\n", ptr2 - ptr1);

    return 0;
}