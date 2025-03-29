#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 220.5;
    printf("data.f: %f\n\n", data.f);

    // Accessing data.i after assigning data.f will show an undefined result
    printf("data.i after data.f: %d\n", data.i);

    // Accessing the char array
    snprintf(data.str, sizeof(data.str), "Hello, Union!");
    printf("data.str: %s\n", data.str);

    return 0;
}