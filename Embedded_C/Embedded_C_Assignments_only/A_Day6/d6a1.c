/*Define a structure named Rectangle that includes two members: length and width, both
of type float. Write a function printRectangle that takes a Rectangle structure as an
argument and prints its length and width.*/


/*To print length and width of a rectangle*/

#include<stdio.h>

// structure rectangle with 2 float members
struct Rectangle {
    float length, width;
} rec;

// Printing the members of the strcuture
void printRectangle(struct Rectangle rec){

    printf("The length of the rectangle: %0.2f\n", rec.length);
    printf("The width of the rectangle: %0.2f\n", rec.width);
}

int main(){

    // reading members of the structure
    printf("Enter the length of the rectangle: ");
    scanf("%f", &rec.length);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &rec.width);

    // Function call to print the vales in structure
    printRectangle(rec);

    return 0;
}