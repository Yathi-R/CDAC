#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    //int arr[3][4];
    int row, col;
    int **ptr = NULL;

    printf("ENter row and col : ");
    scanf("%d %d", &row, &col);

    // allocate memory for storing addresses of rows
    ptr = (int **)malloc(row * sizeof(int *));
    if(ptr == NULL)
    {
        printf("malloc() failed \n");
        exit(1);
    }
    //ptr[0] = (int *)malloc(col * sizeof(int));
    //ptr[1] = (int *)malloc(col * sizeof(int));
    //ptr[2] = (int *)malloc(col * sizeof(int));

    for(int i = 0 ; i < row ; i++)
        ptr[i] = (int *)malloc(col * sizeof(int));

    /*
        // logic of 2D array
    */

    for(int i = 0 ; i < row ; i++)
        for(int j = 0 ; j < col ; j++)
            ptr[i][j] = i + j;

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
            printf("%-4d",ptr[i][j]);
        printf("\n");
    }

    for(int i = 0 ; i < row ; i++)
        free(ptr[i]);

    free(ptr);

    return 0;
}

/*
{
    int (*ptr)[4] = malloc(row * col * sizeof(int));
    ptr[i][j]
}
*/