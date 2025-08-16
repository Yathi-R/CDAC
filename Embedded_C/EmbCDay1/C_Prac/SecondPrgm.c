#include<stdio.h>
#include<limits.h>

int main(){
    
    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(char));
    printf("%ld\n", sizeof(float));
    printf("%ld\n", sizeof(double));
    printf("%d\n", __INT_MAX__);
    printf("%d\n", INT_MIN);

    int a=100,b=10;
    printf("Sum of %d and %d is %d\n",a,b,a+b);
    printf("Sum of %d and %d is %d\n",a,b,a-b);
    printf("Sum of %d and %d is %d\n",a,b,a*b);
    printf("Sum of %d and %d is %d\n",a,b,a/b);
    printf("Sum of %d and %d is %d\n",a,b,a%b);

    return 0;
}