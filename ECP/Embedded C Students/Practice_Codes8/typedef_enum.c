#include <stdio.h>

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

int main() {
    Color myColor = GREEN;
    switch (myColor) {
        case RED:
            printf("Red\n");
            break;
        case GREEN:
            printf("Green\n");
            break;
        case BLUE:
            printf("Blue\n");
            break;
        default:
            printf("Unknown color\n");
    }
    return 0;
}
