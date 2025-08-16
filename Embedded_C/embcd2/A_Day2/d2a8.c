/*Write a C program that demonstrates the order of evaluation in expressions with operators. Use
parentheses to show how operator precedence affects the result.*/

/*Order of evaluation in expression with operators*/

#include<stdio.h>

int main(){

    int x = 30, y = 20, z = 10, result;

    printf("The values of x = %d, y = %d, z = %d\n", x, y, z);

    result = x * y + z / z + y - x;                 /*expression without paranthesis*/
    printf("x*y+z/z+y-x = %d\n", result); 

    result = (x * y + z) / ( z + y) - x;               /*with paranthesis*/
    printf("(x*y+z)/(z+y)-x = %d\n", result);

    result = x * ( y + z) / ( z + y) - x;               /*with paranthesis on diff location*/
    printf("x*(y+z)/(z+y)-x = %d\n", result);

return 0;

}