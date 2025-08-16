/*Static local variable to count from 1 to 5*/

#include<stdio.h>

int fun();

int fun(){
    static int count = 0;
    count++;
    return count;
}
int main(){
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    printf("%d\n", fun());
    return 0;
}


