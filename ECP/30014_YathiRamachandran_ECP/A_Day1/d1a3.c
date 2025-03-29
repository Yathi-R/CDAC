/*Write a C program to print the size (in bytes) of different data types (int, float, double,
char) using the “sizeof” operator.*/

/*To print sizes of different datatypes*/
#include<stdio.h>

int main(){
    
    printf("size of integer: %ld\n", sizeof(int)); // integer data type
    printf("size of float: %ld\n", sizeof(float)); // float data type
    printf("size of double: %ld\n", sizeof(double)); // double data type
    printf("size of char: %ld\n", sizeof(char)); // char data type

    return 0;
}