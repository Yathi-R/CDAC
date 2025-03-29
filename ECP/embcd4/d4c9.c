/*Print elements in 2D array*/

#include<stdio.h>

int main(){
    int row, column;

    printf("Enter height(rows) and width(columns) of the 2D array:");
    scanf("%d%d", &row, &column);

    int arr[row][column];

    printf("Enter the integer array elements:\n");
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<column; j++){
    //         scanf("%d", &arr[i][j]);
    //     }
    // }

    //single for loop for reading the elements
    for(int i=0; i < row*column; i++){
        scanf("%d", &arr[i/column][i%column]);
    }

    printf("Printing the integer array elements:\n");
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<column; j++){
    //         printf("%d\t", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    //single for loop for printing elements
    for(int i=0; i < row*column; i++){
        printf("%d\t", arr[i / column][i % column]);

        if((i + 1) % column == 0){
            printf("\n");
        }
    }
    
return 0;
}