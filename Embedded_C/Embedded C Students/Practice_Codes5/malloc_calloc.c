#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *malloc_arr = (int *)malloc(5 * sizeof(int));
    int *calloc_arr = (int *)calloc(5, sizeof(int));

    if (malloc_arr == NULL || calloc_arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Using malloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", malloc_arr[i]);  // May print garbage values
    }
    printf("\n");

    printf("Using calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", calloc_arr[i]);  // Will print 0 for all elements
    }
    printf("\n");

    free(malloc_arr);
    free(calloc_arr);

    return 0;
}