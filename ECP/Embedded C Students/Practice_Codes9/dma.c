#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};
int main() {
    // Allocate memory for a struct Point
    struct Point *pPtr = (struct Point *)malloc(sizeof(struct Point));
    if (pPtr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    // Initialize members
    pPtr->x = 30;
    pPtr->y = 40;
    // Access members
    printf("x: %d, y: %d\n", pPtr->x, pPtr->y); // Output: x: 30, y: 40
    // Free allocated memory
    free(pPtr);
    return 0;
}