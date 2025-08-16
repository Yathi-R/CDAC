#include <stdio.h>

enum Status { Pending = 1, InProgress = 2, Completed = 3 };

int main() {
    enum Status task = InProgress;
    printf("The value of task is %d\n", task);  // Output: The value of task is 2

    return 0;
}
