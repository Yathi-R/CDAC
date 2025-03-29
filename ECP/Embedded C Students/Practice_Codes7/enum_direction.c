#include <stdio.h>
enum Direction { North, East, South, West };
void move(enum Direction d) {
    switch (d) {
        case North:
            printf("Moving North\n");
            break;
        case East:
            printf("Moving East\n");
            break;
        case South:
            printf("Moving South\n");
            break;
        case West:
            printf("Moving West\n");
            break;
        default:
            printf("Invalid direction\n");
    }
}
int main() {
    enum Direction dir = North;
    move(dir);  // Output: Moving North

    dir = 6;  // This is allowed but may not be meaningful
    move(dir);  // Output: Invalid direction

    return 0;
}