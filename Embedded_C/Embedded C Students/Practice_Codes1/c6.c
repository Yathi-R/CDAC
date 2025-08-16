#include<stdio.h>

/*
    sizeof() 
    - it is an operator
    - it gives size of variable, data type, constants
    - syntax :: sizeof(<var/data type/constant>);
    - we can not perform any operation in sizeof(operator)
*/

int main(void)
{
    int num  = 0;
    char ch = 'D';
    float flt;
    double d;
    
    printf("sizeof(num) = %d\n", sizeof(num));
    printf("sizeof(ch) = %d\n", sizeof(ch));
    printf("sizeof(flt) = %d\n", sizeof(flt));
    printf("sizeof(d) = %d\n", sizeof(d));

    printf("sizeof(int) = %d\nsizeof(char) = %d\n", sizeof(int), sizeof(char));

    printf("sizeof(10) = %d\n", sizeof(10));        //4
    printf("sizeof('D') = %d\n", sizeof('D'));      //4

    printf("sizeof(C-DAC) = %d\n", sizeof("C-DAC"));        // 6
    printf("sizeof(3.14) = %d\n", sizeof(3.14));            // 8    // double
    printf("sizeof(3.14f) = %d\n", sizeof(3.14f));          // 4    // float

    printf("before :: num = %d\n", num);
    printf("sizeof(10 + 20) = %d\n", sizeof(num = 10 + 20));
    printf("sizeof(10 + 'A') = %d\n", sizeof(num = 10 + 'A'));
    printf("sizeof(10 + 20) = %d\n", sizeof(ch = 10 + 20));
    printf("after :: num = %d\n", num);

    return 0;
}