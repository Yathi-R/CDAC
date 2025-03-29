/*Write a C program to define int, float, string and character variables also print their
values in console.*/

/*To define and print values of different data types (int, float, string, char)*/

#include<stdio.h>

int main(){

    int serial_no = 145; //int data type
    char name[] = "Yathi"; //char(string) data type
    float avg_marks = 75.95; // floar data type
    char grade = 'A'; //char data type

    //printing the values of different datatypes
    printf("Serial no:%d\n", serial_no);
    printf("Name:%s\n", name);
    printf("Average marks scored is %0.2f\n", avg_marks);
    printf("Grade: %c\n", grade);

    return 0;
}