/* Write a C program to check maximum and minimum number. The numbers should be
entered by user.*/

#include<stdio.h>

int main(){

    int n, num, max, min;

    //Getting the number of integers from the user
    printf("Enter the no of integers to check: ");
    scanf("%d", &n);

    //input validation
    if (n <= 0){
        printf("Number of integers can't be 0 or less:\n");
        return 1;
    }

    //Taking first number as user input
    printf("Enter the first number: ");
    scanf("%d", &num);

    //assigning first number to max and min
    max = num;
    min = num;

    //using loop to get other numbers and finding MAX & MIN
    for (int i = 2; i <= n; i++){
        printf("Enter the next number: ");
        scanf("%d", &num);

        //Finding MAX
        if(num >= max){
            max = num;
        }
        //Finding Min
        if(num <= min){
            min = num;
        }

    }

    //Displaying MAX and MIN number
    printf("The maximum number is: %d\n", max);
    printf("The minimum number is: %d\n", min);

return 0;

}