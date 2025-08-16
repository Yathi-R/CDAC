#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;

    printf("Value of num: %d\n", num);

    printf("Address of num: %p\n", (void *)ptr);

    printf("Value at address stored in ptr: %d\n", *ptr);

    printf("Value at address stored in ptr: %d\n\n", &ptr);

    printf("address of num: %d\n\n", &num);

    printf("address of num: %d\n\n", ptr);
    printf("address of num: %d\n\n", &ptr);




    int num1 = 100;
    int *ptr1 = &num1;

    printf("Value of num: %d\n", num1);
    printf("Address of num: %p\n", (void *)ptr1);
    printf("Value at address stored in ptr: %d\n", *ptr1);


    return 0;
}