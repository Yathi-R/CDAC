#include <stdio.h>

// Define the Rectangle structure
typedef struct {
    float length;
    float width;
} Rectangle;

// Function to print the details of the Rectangle
void printRectangle(Rectangle rect) {
    printf("Length: %.2f\n", rect.length);
    printf("Width: %.2f\n", rect.width);
}

// Function to calculate the area of the Rectangle
float calculateArea(Rectangle rect) {
    return rect.length * rect.width;
}

// Function to print the area of the Rectangle
void printArea(Rectangle rect) {
    float area = calculateArea(rect);
    printf("Area: %.2f\n", area);
}
int main() {
    // Create and initialize a Rectangle instance
    Rectangle myRect;
    myRect.length = 10.5;
    myRect.width = 5.75;

    // Print the details of the Rectangle
    printRectangle(myRect);
    printArea(myRect);

    return 0;
}