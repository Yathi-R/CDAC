#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char *ptr[4];
    char str[24];
    //char *str;

    for(int i =  0 ;  i  < 4  ; i++)
    {
        printf("Enter ptr[%d] : ",i);
        scanf("%s", str);
        //ptr[i] = (char *)malloc((strlen(str) + 1) * sizeof(char));
        ptr[i] = (char *)calloc(strlen(str) + 1 , sizeof(char));
        strcpy(ptr[i], str);
    }

    for(int i = 0 ; i < 4 ; i++)
        printf("ptr[%d] = %s\n", i, ptr[i]);

    for(int i = 0 ; i < 4 ; i++)
        free(ptr[i]);

    return 0;
}