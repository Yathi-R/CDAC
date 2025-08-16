/* Count of ODD and EVEN elements in the array*/

#include<stdio.h>

int main(){
    
    int n;

    printf("Enter the number of elements for array:");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter the elements of integer array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    int oddcount = 0, evencount = 0;
    
    for(int j=0; j<n; j++){
        if( numbers[j] % 2 == 0){
            evencount++;
        }
        else {
            oddcount++;
        }
        
    }
    
    printf("The sum of EVEN elements in the array is %d\n", evencount);
    printf("The sum of ODD elements in the array is %d\n", oddcount);

 
return 0;
}