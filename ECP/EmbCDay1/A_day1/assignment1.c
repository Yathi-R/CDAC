/*To define and print values of different data types (int, float, string, char)*/

#include<stdio.h>

int main(){

    int serial_no= 145;
    char name[]="Yathi";
    float avg_marks=75;
    char grade='A';

    printf("Serial no:%d\n", serial_no);
    printf("Name:%s\n", name);
    printf("Average marks scored is %0.2f\n", avg_marks);
    printf("Grade: %c\n", grade);

    return 0;
}