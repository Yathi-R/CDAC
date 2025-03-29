#include <stdio.h>

// function prototypes
void getnumbers(int *num1, int *num2);
void addnumbers(int *num1, int *num2, int *sum);
void displaynumbers(int *num1, int *num2, int *sum);

int main() {
    int num1, num2, sum;
    
    // function calling for different functionalities
    getnumbers(&num1, &num2);  // pass address of num1 and num2
    addnumbers(&num1, &num2, &sum);  // pass address of num1, num2, and sum
    displaynumbers(&num1, &num2, &sum);  // pass address of num1, num2, and sum

    return 0;
}

// getting 2 numbers from user using function
void getnumbers(int *num1, int *num2) {
    // getting 2 numbers from user
    printf("Enter 2 numbers: ");
    scanf("%d%d", num1, num2);  // directly store values in num1 and num2 using pointers
}

// adding 2 numbers using function
void addnumbers(int *num1, int *num2, int *sum) {
    *sum = *num1 + *num2;  // dereference pointers to access values and store the result in sum
}

// displaying sum using function
void displaynumbers(int *num1, int *num2, int *sum) {
    printf("The sum of %d and %d = %d\n", *num1, *num2, *sum);  // dereference pointers to print values
}
