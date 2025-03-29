/*Print elements of arrays using do-while loop*/

#include<stdio.h>

int main(){
    
    int n;

    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n], i=0;

    printf("Enter the elements of integer array:\n");
    
    do{
        scanf("%d", &numbers[i]);
        i++;
    }while(i<n);

    printf("\nPrinting the elements of array:\n");

    i=0;
    do{
        printf("Number at %d position in the array is %d\n", i, numbers[i]);
        i++;
    }while(i<n);

return 0;
}