#include <stdio.h>
enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
int main() {

    enum Day today;
    today = Wednesday;
    printf("The value of today is %d\n", today);  // Output: The value of today is 2

    return 0;
}