#include<stdio.h>
#include <string.h>

typedef int* IntPtr;
typedef char * strPtr;
typedef float* floPtr;
typedef double* doubPtr;

typedef struct {
    int serial_no;
    char laptop_model[50];
    float price;
    double speed;
} laptop;

int main(){

    laptop lap= {12345, "Dell Latitude 5420", 40000.00, 1.5e12};

    printf("laptop serial no: %d\n", lap.serial_no);
    printf("Laptop Model : %s\n", lap.laptop_model);
    printf("Laptop Model : %f\n", lap.price);
    printf("Laptop Model : %lf\n", lap.speed);

    IntPtr iPtr = &lap.serial_no;
    strPtr sPtr = lap.laptop_model;
    floPtr fPtr = &lap.price;
    doubPtr dPtr = &lap.speed;

    *iPtr = 54321;
    strcpy( sPtr, "HP G10");
    *fPtr = 35500.01;
    *dPtr = 1.35e12;

    printf("\nAfter modification using Pointer:\n");
    printf("laptop serial no: %d\n", lap.serial_no);
    printf("Laptop Model : %s\n", lap.laptop_model);
    printf("Laptop Model : %f\n", lap.price);
    printf("Laptop Model : %lf\n", lap.speed);

return 0;
}