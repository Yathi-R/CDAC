/*Max of 4 user given integer numbers*/

#include<stdio.h>

int main(){

    int num1, num2, num3, num4;
    num1=num2=num3=num4=0;

    printf("Enter 4 integer numbers to find MAX among them: \n");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);                /*Getting user input*/

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
        
return 0;
}