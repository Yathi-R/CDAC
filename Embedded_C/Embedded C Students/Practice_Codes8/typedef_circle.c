#include <stdio.h>
#include <math.h>  // For M_PI constant

// Define the typedef for Real
typedef double Real;

// Function to calculate the area of a circle
Real calculateCircleArea(Real radius) {
    return M_PI * radius * radius;
}

int main() {
    // Define the radius of the circle
    Real radius = 5.5;
    
    // Calculate the area
    Real area = calculateCircleArea(radius);
    
    // Print the result
    printf("The area of a circle with radius %.2f is %.2f\n", radius, area);
    
    return 0;
}