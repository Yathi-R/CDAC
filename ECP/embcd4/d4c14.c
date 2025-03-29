/*Print elements of arrays in reverse*/

#include<stdio.h>

int main(){
    
    int n;

    //Getting the size of the array
    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n];

    //getting array elements from user
    printf("Enter the elements of integer array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &numbers[i]);
    }

    //displaying the elements of array before reversing
    printf("\nPrinting the elements of array before reversing:\n");
    for(int i=0; i<n; i++){
        printf("Number at %d position in the array is %d\n", i, numbers[i]);
    }

    //Reversing the array using for loop
    int temp = numbers[0]; 
    
    for(int i=0; i < n/2; i++){
        numbers[i] = numbers[n-1-i];
        numbers[n-1-i] = temp;
        temp = numbers[i+1];
    }

    //Displaying the reversed array
    printf("\nPrinting the elements of reversed array:\n");
    
    for(int i = 0; i<n; i++){
        printf("Number at %d position in the reversed array is %d\n", i, numbers[i]);
    }
    
return 0;
}