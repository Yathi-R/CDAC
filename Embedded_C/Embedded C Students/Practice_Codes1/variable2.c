#include <stdio.h>

void count() {
    static int count = 0; // Static local variable
    count++;
    printf("Count = %d\n", count);
}

int main(void) {
    count();
    count();
    count();
    return 0;
}