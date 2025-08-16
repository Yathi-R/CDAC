/*Write a C program to define a macro “area” to calculate area of a circle after providing
radius by user*/

/*Calculating area of circle using macro*/
#include<stdio.h>

//defining Macro for Pi value and area of circle
#define Pi 3.14159
#define area_circle(radius) (Pi * radius * radius)


int main(){

    float radius, area;

    //Taking Radius from user
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    //Input validating
    if(radius >0){
        area = area_circle(radius); //calc area of circle using Macro area_circle
    }else{
        printf("Entered Radius: %0.2f and it can't be 0 or less.\n", radius);
        return 1;
    }
    
    //Displaying the radius and area of circle
    printf("Area of the circle with radius ~%0.2f is %.6f\n", radius, area);

    return 0;
}