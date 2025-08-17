/*Print elements of arrays using while loop*/

#include<stdio.h>

int main(){
    
    int n;

    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n], i=0;

    printf("Enter the elements of integer array:\n");
    
    while(i<n){
        scanf("%d", &numbers[i]);
        i++;
    }

    printf("\nPrinting the elements of array:\n");

    i=0;
    while(i<n){
        printf("Number at %d position in the array is %d\n", i, numbers[i]);
        i++;
    }

return 0;
}