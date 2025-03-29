#include<stdio.h>

int main(void)
{
    int num;
    int i;

    printf("Enter Number :  ");
    scanf("%d", &num);

    // initialization ; condition ; modification
    for(i = 1 ; i <= 10 ; i++)
    {
        //body
         printf("%d\n", i * num);     
    }
    return 0;
}