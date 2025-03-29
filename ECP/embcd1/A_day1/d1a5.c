/*write a C program to print 5 integers in a row and then in different rows without using
any loop.*/

/*To print in a row and in different rows without loop*/

#include<stdio.h>

int main(){

    int a[5]= {1,2,3,4,5};
    printf("%d %d %d %d %d\n%d\n%d\n%d\n%d\n%d\n", a[0], a[1], a[2], a[3], a[4], a[0], a[1], a[2], a[3], a[4]);
    
return 0;
}