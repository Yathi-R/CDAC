/*Print elements of arrays using for loop*/

#include<stdio.h>

int main(){
    
    int n;

    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n], i;

    printf("Enter the elements of integer array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &numbers[i]);
    }

    printf("\nPrinting the elements of array:\n");
    for(i=0; i<n; i++){
        printf("Number at %d position in the array is %d\n", i, numbers[i]);
    }

return 0;
}