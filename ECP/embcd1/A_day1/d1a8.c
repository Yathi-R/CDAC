/*Write a C program to print table of number entered by user using printf and scanf
functions.*/

/*To print table of number given by user*/

#include<stdio.h>

int main(){

    int table;

    //getting number from user using scanf
    printf("Enter a timestable number:");
    scanf("%d", &table);
    
    printf("Multiplication table of %d:\n", table);

    //printing table of number using printf 
    for(int i = 1; i <= 16; i++){
            printf("%d X %d = %d\n", i, table, i * table);
        }
    
    return 0;
}