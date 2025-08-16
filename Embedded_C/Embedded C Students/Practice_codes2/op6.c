#include<stdio.h>

int main(void)
{ 

int a = 5;    // 0101 in binary
int b = 9;    // 1001 in binary

int result = a & b;    // result = 1 (0001 in binary)
printf("result = %d\n", result);

result = a | b;        // result = 13 (1101 in binary)
printf("result = %d\n", result);

result = a ^ b;        // result = 12 (1100 in binary)
printf("result = %d\n", result);

result = ~a;           // result = -6 (two's complement)
printf("result = %d\n", result);

result = a << 1;       // result = 10 (1010 in binary)
printf("result = %d\n", result);

result = a >> 1;       // result = 2 (0010 in binary)
printf("result = %d\n", result);

return 0;
}
