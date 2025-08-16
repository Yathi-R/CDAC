#include<stdio.h>

int main(void)
{
    int i = 1;
    /*
    while(1)
    {
        printf("%d : PG-DESD\n", i++);
        if(i == 100)
            break;
    }*/
    while(1)
    {
        if(i == 100)
            continue;
        printf("%d : PG-DESD\n", i++);
    }
    return 0;
}