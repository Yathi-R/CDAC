/*Write a C code to check if bit2 and bit3 are both set. Print whether they are both set or not.*/

#include<stdio.h>

//typedefining unsighned int to uInt
typedef unsigned int uint; 

//typedefined struct as Reg
typedef struct {
    uint bit:4;
} Reg;

int main(){

    Reg b1;

    //assigning value to bit in struct
    b1.bit = 1;
    uint value;

    // Testing/checking bits using Bitwise & and right shift >> oper
    value = (b1.bit >> 2) & 3;

    //printing if both bits are et or not
    if( value == 3){
        printf("Both Bits 2 and 3 are set\n");
    }
    // else if (value == 2){
    //     printf("Only Bit 3 is set\n");
    // }
    // else if ( value == 1){
    //     printf("Only Bit 2 is set\n");
    // }
    else{
        printf("Either or Both bits are not set\n");
    }
    

    return 0;
}