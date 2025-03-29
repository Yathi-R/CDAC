#include<stdio.h>

int main(void)
{
    int num;
    int i;

    printf("Enter Number :  ");
    scanf("%d", &num);

    i = 1;// initialization
    while(i <= 10)// condition
    {
        //body
         printf("%d\n", i * num);
        // modification
        i++;
    }
    return 0;
}