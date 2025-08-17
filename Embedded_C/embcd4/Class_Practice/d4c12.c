/*SUM of element in the array*/

#include<stdio.h>

int main(){
    
    int n;

    //Getting size of array from user
    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n];

    //Getting elements of the array
    printf("Enter the elements of integer array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    //Calculating the Sum of the array elements and displaying
    int sum = 0;
    
    for(int j=0; j<n; j++){
        sum += numbers[j];
    }
    
    printf("The sum of the elements in the array is %d\n", sum);

 
return 0;
}