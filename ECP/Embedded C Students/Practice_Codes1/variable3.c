#include <stdio.h>
int globalVar = 10;									// Global variable

void func1() {
int localVar = 20;									// Local variable

printf("Local variable in func1: %d\n", localVar);
globalVar = 30;										// Accessing global variable

    printf("Global variable in func1: %d\n", globalVar);
}


void func2() {
    static int staticVar = 0;  						// Static local variable
    staticVar++;
    globalVar++;
    printf("Static variable in func2: %d\n", staticVar);
    //printf("Static variable in func2: %d\n", localVar);
}


int main() {
    func1();
    func2();
    func2();							// Accessing global variable in main
    printf("Global variable in main: %d\n", globalVar);
    return 0;
}
