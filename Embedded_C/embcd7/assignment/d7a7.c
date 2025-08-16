/*Write a C program to perform bitwise left and right shift operations.*/

#include<stdio.h>

// Type defining unsighned int data type as uInt
typedef unsigned int uInt;

int main(){

    //Declaring and Initializing variables using alias uInt 
    uInt x = 0xF0F0F0F0, y;

    //right shifting x to 3 positions
    y = x >> 3;
    printf("after right shifting 0x%X to 3 position: 0x%X\n", x, y);

    printf("after left shifting 0x%X to 3 position: ", y);
    //left shifting y to 3 positions
    y = y << 3;
    printf("0x%X\n", y);

    return 0;
}