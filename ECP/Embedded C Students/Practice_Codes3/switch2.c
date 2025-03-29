#include<stdio.h>

// take month number from user and print how many days are there in that month.

int main(void)
{
    int month;
    int num1, num2;

    printf("Enter month number : ");
    scanf("%d", &month);

    switch(month)
    {
        //case 1:
        //case "jan": //invalid
        case 'J':
        //case 0x1:
        //case 01:
        //case 0 + 1:
        case 0 || 1:
        //case num1 + num2; // invalid
            printf("Number of Days (jan): 31\n");
            break;
        case 2:
            printf("Number of Days (feb): 28/29\n");
            //break;
        case 3:
            printf("Number of Days (mar): 31\n");
            break;
        //case 1:// duplicate case
        case 4:
            printf("Number of Days (apr): 30\n");
            break;
        case 5:
            printf("Number of Days (may): 31\n");
            break;
        default:
           printf("Invalid month number\n");
           break;
    }

    return 0;
}