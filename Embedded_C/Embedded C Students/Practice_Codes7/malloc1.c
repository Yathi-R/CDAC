#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int count;
    int *ptr = NULL;

    printf("Enter count of array elements : ");
    scanf("%d", &count);

    ptr = (int *)malloc(count * sizeof(int));

    printf("Enter array elements : \n");
    for(int i = 0 ; i < count ; i++)
    {
        printf("ptr[%d] = ", i);
        scanf("%d", &ptr[i]);
    }

    printf("array elements are : \n");
    for(int i = 0 ; i < count ; i++)
    {
        printf("%-4d", ptr[i]);
    }
    printf("\n");
    free(ptr);

    return 0;
}