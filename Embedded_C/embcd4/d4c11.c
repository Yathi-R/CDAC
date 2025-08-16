/*Largest and smallest element in the array*/

#include<stdio.h>

int main(){
    
    int n;

    //Getting size of array from user
    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n];

    //getting the elements of the array
    printf("Enter the elements of integer array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    //initializing largest and smallest
    int largest = numbers[0], smallest = numbers[0];

    //find the largest and smallest element using for loop anf IF, else if condition 
    for(int j = 1; j < n; j++){
        if ( numbers[j] >= largest){
            largest = numbers[j];
        }
        else if( numbers[j] <= smallest) {
            smallest = numbers[j];
        }
    }

    //printing the largest and smallest element from the user given array elements
    printf("The largest number in the array is %d\n", largest);

    printf("The smallest number in the array is %d\n", smallest);


return 0;
}