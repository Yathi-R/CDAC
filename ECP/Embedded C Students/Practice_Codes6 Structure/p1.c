#include <stdio.h>

static enum Days { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday } weekDay;

int main() {
    weekDay = Monday;
    printf("Weekday value: %d\n", weekDay);  // Output: Weekday value: 4

    return 0;
}