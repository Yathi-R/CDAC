#include <stdio.h>
#include <string.h>

int main() {
    char str1[12] = "Hello";
    char str2[8] = " World";
    strncat(str1, str2, 6);
    printf("Concatenated string: %s\n", str1);
    return 0;
}
