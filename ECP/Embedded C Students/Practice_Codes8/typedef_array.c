#include <stdio.h>
typedef int IntArray[5];

int main() {
    IntArray arr = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}