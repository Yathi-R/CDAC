#include<stdio.h>

int main(void)
{
    char str[64];
    FILE *fp = fopen("f07.txt", "w");

    printf("ENter 5 strings :\n");
    for(int i = 0 ; i < 5 ; i++)
    {
        scanf("%*c%[^\n]s", str);
        fputs(str, fp);
        fputs("\n", fp);
    }

    fclose(fp);

    return 0;
}