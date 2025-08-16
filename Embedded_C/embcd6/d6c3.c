/* Simple struct and Union and it's memory allocation*/

#include<stdio.h>

struct person {
    int a;
    float b;
    char str[20];
}p1;

union employee {
    int a;
    float b;
    char str[20];
}e1;
    

int main(){

    printf("%ld\n", sizeof(p1));
    printf("%ld\n", sizeof(e1));

return 0;
}