/* Write a C program to check maximum and minimum number. The numbers should be
entered by user.*/

/*Max & MIN of 4 user given integer numbers*/

#include<stdio.h>

int main(){

    int num1, num2, num3, num4;
    
    printf("Enter 4 integer numbers to find MAX among them: \n");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);                /*Getting user input*/

    /*Finding maximum number*/
        if(num1 >= num2 && num1 >=num3 && num1>=num4){            /* checking if num1 is greatest of all*/
            printf("The maximum number is %d\n", num1);
        }

        else if(num2 >=num3 && num2>=num4){                       /* checking if num2 is greatest and prints*/
            printf("The maximum number is %d\n", num2);
        }

        else if(num3 >=num4){                                     /* checking if num3 is greatest and prints*/
            printf("The maximum number is %d\n", num3);
        }

        else{                                                       /*prints num4 as greatest*/
            printf("The maximum number is %d\n", num4);
        }
        
    /*Finding minimum number*/
        if(num1 <= num2 && num1 <= num3 && num1 <= num4){  /*checks if num1 is smallest of all and prints*/
            printf("The minimum number is %d\n", num1);
        }

        else if(num2 <= num3 && num2 <= num4){             /*checks if num2 is smallest and prints*/
            printf("The minimum number is %d\n", num2);
        }

        else if(num3 <= num4){                             /*checks if num3 is smallest and prints*/
            printf("The minimum number is %d\n", num3);
        }

        else{                                             /*prints num4 is smallest*/
            printf("The minimum number is %d\n", num4);
        }

return 0;
}