/* Write a function that calculates the area of a circle given its radius using the Real typedef. Print
the result in main.*/

/*Calculate area of a circle*/

#include<stdio.h>

// Type defining Real as float
typedef float Real;

// Function to calculate the area of the circle 
Real calcArea(Real radius, Real pi){
    
    return pi *radius * radius;
}

int main(){

    //constant value pi
    const Real pi = 3.14159;

    Real radius, area;

    //Taking radius from user
    printf("Enter the radius of the circle:");
    scanf("%f", &radius);

    //Fun calling to calc area
    area = calcArea(radius, pi);

    printf("The area of the circle with radius %f: %f\n", radius, area);

    return 0;
}