#include<stdio.h>
/*
    Increment/ Decrement operator
    1. Pre increment/decrement
        - value of variable is incremented/decremented first and then updated value is used in the expression

    2. Post increment/decrement
        - value of variable is used in expression and then it is incremented/decremented
*/


int main(void)
{
    int res = 0, num = 8;

   
    // pre increment
    printf("res = %d, num = %d\n", res, num);
    res = ++num;
        // num = num + 1        
        // res = num            
    printf("res = %d, num = %d\n", res, num);
        

    // pre decrement
    printf("res = %d, num = %d\n", res, num);
    res = --num;
        // num = num - 1        
        // res = num            
    printf("res = %d, num = %d\n", res, num);
    
    // post increment
    printf("res = %d, num = %d\n", res, num);
    res = num++;
        // res = num        
        // num = num + 1    
    printf("res = %d, num = %d\n", res, num);
    

   // post decrement
    printf("res = %d, num = %d\n", res, num);
    res = num--;
        // res = num        
        // num = num - 1    
    printf("res = %d, num = %d\n", res, num);
    
    return 0;
}