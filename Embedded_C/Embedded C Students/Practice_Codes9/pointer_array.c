#include <stdio.h>
struct Point {
    int x;
    int y;
};
int main() {
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *pPtr = points; // pPtr points to the first element of the array
    for (int i = 0; i < 3; i++) {
        printf("Point %d -> x: %d, y: %d\n", i, (pPtr + i)->x, (pPtr + i)->y);
    }
    return 0;
}