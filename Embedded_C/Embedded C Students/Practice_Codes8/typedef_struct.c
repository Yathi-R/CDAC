#include <stdio.h>
typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p1;
    p1.x = 10;
    p1.y = 20;

    printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);  // Output: Point coordinates: (10, 20)

    Point a1;
    a1.y = 60;
    a1.x = 100;

    printf("Point coordinates: (%d, %d)\n", a1.x, a1.y); 
    return 0;
}