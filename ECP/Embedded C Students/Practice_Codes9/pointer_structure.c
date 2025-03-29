#include <stdio.h>
struct Point {
    int x;
    int y;
};
int main() {
    struct Point p = {10, 20};
    struct Point *pPtr = &p; // pPtr is a pointer to struct Point
    // Accessing members using the pointer
    printf("x: %d, y: %d\n", pPtr->x, pPtr->y); // Output: x: 10, y: 20
    return 0;
}