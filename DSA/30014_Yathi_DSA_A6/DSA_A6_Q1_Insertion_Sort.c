//Insertion sort Algorithm for sorting array in assending order 

#include<stdio.h>

//Function to sort array by Insertion sort algorithm
void insertionsort(int arr[], int size){

    for(int i = 1; i < size; i++){
        // Current element to be inserted
        int key = arr[i];

        //pointing index previous to key element
        int j = i-1;

        // Move elements greater than key one position ahead
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        //Inserts the key element to correct position
        arr[j+1] = key;
    }
    
}

//Function to display elements in the array
void display(int a[], int size){
    for (int i = 0; i< size; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){

    int arr[] = {45, 98, 12, 0, 34, -99, 100};

    //Calculation the size of the array
    int size = sizeof(arr)/sizeof(int);

    //Printing elements before sorting
    printf("Array elements before sorting:\n");
    display(arr, size);

    //Calling function to perform Insertion sorting
    insertionsort(arr, size);

    //Printing elements in array after sorting in assending order
    printf("Array elements after sorting:\n");
    display(arr, size);

    return 0;
}