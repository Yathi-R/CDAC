#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}
int main() {
    int size = 5;
    int *array = createArray(size);

    for (int i = 0; i < size; i++) {
        array[i] = i * 10;
        printf("%d ", array[i]);
    }

    free(array);  // Free allocated memory

    return 0;
}