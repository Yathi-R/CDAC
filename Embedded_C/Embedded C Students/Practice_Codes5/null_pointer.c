#include<stdio.h>

/*
    int num = 0;

    int *ptr = NULL;

    --> NULL - 0 typecasted with void pointer
    --> void pointer - is a generic pointer in which we can store address of any type of variable
    NULL ==> (void *)0
*/

int main(void)
{
    int *ptr = NULL;        //0

    int *p1 = ptr + 1;      // ptr + 1 * SF(int *) --> ptr + 4  --> 0 + 4   --> 4
    int *p2 = ptr + 3;      // ptr + 3 *SF(int *) --> ptr + 12  --> 0 + 12  -> 12
   
    printf("p1 = %u, p2 = %u\n", p1, p2);

    printf("p2 - p1 = %d\n", p2 - p1);
    // p2 - p1 ==> (p2 - p1) / SF(p2)
    // (12 - 4) / 4 ==> 8 / 4 ==> 2
    return 0;
}