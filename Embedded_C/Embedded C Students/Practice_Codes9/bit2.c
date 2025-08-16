#include <stdio.h>

struct {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int value : 6;
} status;
int main() {
    status.flag1 = 1;  // Set flag1
    status.flag2 = 0;  // Clear flag2
    status.value = 45; // Set value (6 bits, range: 0-63)
    printf("flag1: %d\n", status.flag1);
    printf("flag2: %d\n", status.flag2);
    printf("value: %d\n", status.value);
    return 0;
}