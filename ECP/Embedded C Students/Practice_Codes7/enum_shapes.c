#include <stdio.h>

typedef enum {
    CIRCLE, RECTANGLE, TRIANGLE
} ShapeType;

void describeShape(ShapeType shape) {
    switch (shape) {
        case CIRCLE:
            printf("CIRCLE: A round shape.\n");
            break;
        case RECTANGLE:
            printf("RECTANGLE: A shape with four right angles.\n");
            break;
        case TRIANGLE:
            printf("TRIANGLE: A shape with three sides.\n");
            break;
        default:
            printf("Unknown shape.\n");
    }
}

int main() {
    ShapeType shape = RECTANGLE;
    describeShape(shape);
    return 0;
}