/*Define a structure Circle with members radius (float) and color (string of 20 characters).
Write a function updateRadius that takes a pointer to a Circle structure and a new radius
value, updates the radius of the circle, and then prints the updated radius.*/

/* Struct Circle with radius and color, use function pointer to update radius and print the same]*/

#include<stdio.h>
#include<string.h>

// Structure with 2 members radius and color
struct Circle {

    float radius;
    char color[20];
    
};

// Function to update radius in Circle using pointer and print
void updateRadius(struct Circle *c1, float newRadius){

    c1->radius = newRadius;
    printf("Radius after updating: %0.2f\n", c1->radius); 
}


int main(){

    //Initializing struct Circle with radius and color 
    struct Circle c1 = {3.50, "Green"};
    
    //Printing the radius and color in structure Circle
    printf("Radius before updating: %0.2f\n", c1.radius);
    printf("Color of the circle: %s\n", c1.color);
  
    float newRadius;
    printf("Enter the new radius: ");
    scanf("%f", &newRadius);

    //Fun to pass circle as pointer and new radius
    updateRadius(&c1, newRadius);

    return 0;
}