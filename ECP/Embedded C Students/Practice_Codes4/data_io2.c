#include <stdio.h>
int main() {
    int num;
    float pi;
    char ch;
    char str[100];
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Enter a float: ");
    scanf("%f", &pi);
    printf("Enter a character: ");
    scanf(" %c", &ch);  // Note the space before %c to consume any leftover whitespace
    printf("Enter a string: ");
    scanf("%s", str);  // Reads a single word (up to the first whitespace)
    printf("You entered: %d, %.2f, %c, %s\n", num, pi, ch, str);
    return 0;
}