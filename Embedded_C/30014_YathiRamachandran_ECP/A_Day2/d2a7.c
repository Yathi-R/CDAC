/*Write a C program that demonstrates the effects of type casting on arithmetic operations. The
program should perform division with both integer and floating-point types and show how the
results differ.*/

/*Type casting on arithmetic operator "/" */

#include<stdio.h>

int main(){

    int a = 67, b=13, idiv;
    float fdiv;

    idiv = a/b;                     /*Integer division*/
    fdiv = (float)(a)/b;            /*Type casting a to float and dividing by b*/ 

    printf("Integer division of %d / %d = %d\n", a, b, idiv);
    printf("Division after type casting to float: %f\n", fdiv);

return 0;
}