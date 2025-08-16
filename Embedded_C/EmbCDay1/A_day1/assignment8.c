/*To print table of number given by user*/

#include<stdio.h>

int main(){

    int table;

    printf("Enter a timestable number:");
    scanf("%d", &table);
    
    for(int i=1; i<=20;i++){
            printf("%d X %d = %d\n", i, table, i*table);
        }
    
return 0;
}