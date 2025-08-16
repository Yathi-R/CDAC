#include <stdio.h>
enum Color { Red, Green, Blue };
void printColor(enum Color c) {
    switch (c) {
        case Red:
            printf("Red\n");
            break;
        case Green:
            printf("Green\n");
            break;
        case Blue:
            printf("Blue\n");
            break;
        default:
            printf("Unknown color\n");
    }
}
int main() {
    enum Color myColor = Green;
    printColor(myColor);  // Output: Green

    return 0;
}