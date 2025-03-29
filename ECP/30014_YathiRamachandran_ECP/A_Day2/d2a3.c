/*Write a C program that initializes a variable x to 10. Use compound assignment operators to
increment x by 5, decrement x by 2, multiply x by 3, and divide x by 4. Print the final value of x*/

/*Compound assignment operation*/

#include<stdio.h>

int main(){
    
    int x = 10;
    printf("Initial X value is %d\n", x);

    x += 5; /*increment x by 5*/
    printf(" X value after incrementing by 5 is %d\n", x);

    x -= 2; /*decrement x by 2*/
    printf(" X value after decrementing by 2 is %d\n", x);

    x *= 3; /*multiply x by 3*/
    printf(" X value after multiplying by 3 is %d\n", x);

    x /= 4; /*divide x by 4 */
    printf(" X value after dividing by 4 is %d\n", x);

return 0;
}