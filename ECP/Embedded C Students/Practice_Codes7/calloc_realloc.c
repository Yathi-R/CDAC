#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    //float arr[5];
    int count;
    int new_count;
    float *ptr = NULL;
    
    printf("ENter count : ");
    scanf("%d", &count);

    ptr = (float *)calloc(count, sizeof(float));
    if(ptr == NULL)
    {
        printf("malloc() failed\n");
        exit(1);
    }

    for(int i = 0 ; i < count ; i++)
        ptr[i] = (i+1)*3.14f;

    for(int i = 0 ; i < count ; i++)
        printf("%.2f ", ptr[i]);
    printf("\n");

    printf("ENter new count : ");
    scanf("%d", &new_count);
    
    ptr = realloc(ptr, new_count * sizeof(float));
    if(ptr == NULL)
    {
        printf("realloc() failed\n");
        exit(1);
    }
    /*
    1. if you are having imediate space after allocated space
        a. only differance of old size and new size space is allocated
        b. old data is kept as it is
        c. it will return same starting address
    2. if you are not having imediate space after allocated space
        a. new size space will be allocated in memory
        b. old data will be copied inside new space
        c. old space will be freed
        d. address of new space will be returned
    3. if you do not have any memory left to grow on heap
        a. it will not do anything
        b. it will return same starting address of previous space

        ptr = realloc(NULL, size)       ==> malloc
        realloc(ptr, 0)              ==> free
    */

    /*
    for(int i = count ; i < new_count ; i++)
        ptr[i] = (i+1)*3.14f;
    */
    for(int i = 0 ; i < new_count ; i++)
        printf("%.2f ", ptr[i]);

    printf("\n");

    free(ptr);

    return 0;
}