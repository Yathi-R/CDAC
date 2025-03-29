#include<stdio.h>

int main(void)
{
    char str[64];
    FILE *fp = fopen("f06.txt", "w");

    printf("Enter string : ");
    scanf("%[^\n]s", str);

    for(int i = 0 ; str[i] != '\0' ; i++)
        fputc(str[i], fp);

    fclose(fp);

    return 0;
}