#include <stdio.h>

int main(void)
{
    char str[64];
    FILE *fp = fopen("f07.txt", "w");

    // Error checking for file opening
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter 5 strings:\n");
    for(int i = 0; i < 5; i++)
    {
        // Use fgets to read a line of input, including handling of newline
        if (fgets(str, sizeof(str), stdin) != NULL) {
            // Remove newline character if it is there
            size_t len = strlen(str);
            if (len > 0 && str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }
            fputs(str, fp);
            fputs("\n", fp);
        } else {
            // Handle case where fgets fails
            perror("Error reading input");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}