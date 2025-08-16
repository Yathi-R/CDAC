/* Simple struct*/

#include<stdio.h>
#include<string.h>

struct person {
    int a;
    float b;
    char str[20];
};

int main(){

    struct person p1 = {12345, 88.56, "Yathi"};
    struct person p2;
    
    p2.a = 54321;
    p2.b = 9987.09786;
    strcpy(p2.str, "Hello");
 
    printf("%d\n", p1.a);
    printf("%f\n", p1.b);
    printf("%s\n", p1.str);

    printf("%d\n", p2.a);
    printf("%f\n", p2.b);
    printf("%s\n", p2.str);

return 0;
}