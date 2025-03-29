#include <stdio.h>
#include <string.h>
int main() {
    char str1[20] = "Hello";
    char str2[] = "World";
    char str3[20];
    // Copy str1 to str3
    strcpy(str3, str1);
    printf("str3: %s\n", str3);  // Output: str3: Hello
    // Concatenate str1 and str2
    strcat(str1, str2);
    printf("str1: %s\n", str1);  // Output: str1: HelloWorld
// Get the length of str1
    int len = strlen(str1);
    printf("Length of str1: %d\n", len);  // Output: Length of str1: 10
    // Compare str1 and str2
    int cmp = strcmp(str1, str2);
    printf("Comparison result: %d\n", cmp);  // Output: Comparison result: positive number
    return 0;
}