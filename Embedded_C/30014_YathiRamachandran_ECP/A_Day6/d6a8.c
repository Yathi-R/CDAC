/*Define an enum ShapeType with values CIRCLE, RECTANGLE, SQUARE and
TRIANGLE. Write a C program that uses a switch statement to print a description for
each shape type. For example, "CIRCLE: A round shape", "RECTANGLE: A shape
with four right angles", etc.*/

#include <stdio.h>

// Define an enum for ShapeType
enum ShapeType{
    CIRCLE,
    RECTANGLE,
    SQUARE,
    TRIANGLE
};

// Function to print shape description
void printShapeDescription(enum ShapeType shape) {

    switch (shape) {

        case CIRCLE:
            printf("CIRCLE: A round shape.\n");
            break;

        case RECTANGLE:
            printf("RECTANGLE: A shape with four right angles.\n");
            break;

        case SQUARE:
            printf("SQUARE: A rectangle with equal sides.\n");
            break;

        case TRIANGLE:
            printf("TRIANGLE: A shape with three sides.\n");
            break;
            
        default:
            printf("Unknown shape.\n");
    }
}

int main() {

    // function to print shape types
    printShapeDescription(CIRCLE);
    printShapeDescription(RECTANGLE);
    printShapeDescription(SQUARE);
    printShapeDescription(TRIANGLE);
    
    return 0;
}
