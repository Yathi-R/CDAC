#include<stdio.h>

// Calculate power of given base and index
// power = base ^ index

// 2^4 = 2 * 2^3
//     = 2 * 2 * 2^2
//     = 2 * 2 * 2  * 2^1
//     = 2 * 2 * 2 * 2 * 2^0
//     = 2 * 2 * 2 * 2 * 1

// base^index = base * base^index-1
// index == 0       == 1

int power(int base, int index)
{
    /*
    int p;
    if(index == 0)
        return 1;
    p = base * power(base, index - 1);
    return p;
    */

    if(index == 0)
        return 1;
    return base * power(base, index-1);
}

int main(void)
{
    int base, index;

    printf("ENter base : ");
    scanf("%d", &base);

    printf("Enter index : ");
    scanf("%d", &index);

    printf("%d^%d = %d\n", base, index, power(base, index));

    return 0;
}