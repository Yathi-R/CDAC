/*Write A C program to show bit masking and modify specific bits within a variable.
Demonstrates how to use bitwise operators with masks.*/

#include<stdio.h>

//type defining
typedef unsigned short usInt;

int main(){

    usInt n, reg_value = 0xFFA8, mask_value;

    printf("Enter a bit position [0-15]:");
    scanf("%hd", &n);

    if( n >= 0 && n <= 15){
        //masked value to set/clear/toggle/NOT nth bit  
        mask_value = (1 << n);
    }else{
        return 1;
    }
    
    printf("Initial Reg Value: 0x%X\n", reg_value);

    // to set nth bit using mask value
    printf(" Reg_value after setting %d bit: 0x%X\n", n, reg_value |= mask_value);


    // to clear nth bit using mask value (also using NOT ope on masks)
    printf(" Reg_value after clearing %d bit: 0x%X\n", n, reg_value &= ~(mask_value));
    
    //to toggle nth bit using mask value
    printf(" Reg_value after Toggling %d bit: 0x%X\n", n, reg_value ^= mask_value);

    return 0;
}

