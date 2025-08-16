/*Define a union named Vehicle that can store either the number of wheels (int), the
engine capacity (float), or the vehicle type (char[20]). Write a program to demonstrate
how to use this union to store and print all three types of data.*/

#include <stdio.h>
#include<string.h>

// Define a union for Vehicle
union Vehicle {
    int wheels;
    float engineCapacity;
    char type[20];
};

int main() {

    union Vehicle vehicle;
    
    // Store and print number of wheels (int)
    vehicle.wheels = 4;
    printf("Number of Wheels: %d\n", vehicle.wheels);
    
    // Store and print engine capacity
    vehicle.engineCapacity = 2.5;
    printf("Engine Capacity: %.2fL\n", vehicle.engineCapacity);
    
    // Store and print vehicle type
    strcpy(vehicle.type, "Sedan");
    printf("Vehicle Type: %s\n", vehicle.type);
    
    return 0;
}
