#include <stdio.h>
#define PI 3.14159
#define AREA(radius) (PI * (radius) * (radius))
#define DEBUG

int main() {
    double r = 5.0;
    double area = AREA(r);
    printf("Area of circle: %f\n", area);
    #ifdef DEBUG
    printf("Debug mode: Radius = %f, Area = %f\n", r, area);
    #endif
    return 0;
}