#include <stdio.h> 
// Function to calculate sum of array elements 

int sumArray(int arr[], int size) { 
	// Base case 
	if (size <= 0) { 
	return 0; 
	} 
    
	// Recursive case 
	return arr[size - 1] + sumArray(arr, size - 1); 
} 

int main() { 
	int arr[] = {1, 2, 3, 4, 5}; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	printf("Sum of array elements is %d\n", sumArray(arr, size)); 
	return 0; 	
    }
