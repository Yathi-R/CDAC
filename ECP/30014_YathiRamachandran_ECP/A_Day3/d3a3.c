/*Take month number from user and print how many days are there in that month by
using switch statements.*/

/*To print number of days in each month using switch*/

#include <stdio.h>

int main() {

    int month;

    // Getting user input
    printf("Enter month number from 1 to 12: ");
    scanf("%d", &month);

    // Using switch to print number of days in that month
    switch(month) {

        case 1: printf("January has 31 days\n");
            break;

        //checking if Leap year or not
        case 2: printf("Enter year in yyyy format to check if it's a leap year or not: ");

                int year;
                scanf("%d", &year);

                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                    printf("February has 29 days (Leap year)\n");
                } 
                
                else {
                    printf("February has 28 days (not a Leap year)\n");
                }
            break;

        case 3: printf("March has 31 days\n");
            break;

        case 4: printf("April has 30 days\n");
            break;

        case 5: printf("May has 31 days\n");
            break;

        case 6: printf("June has 30 days\n");
            break;

        case 7: printf("July has 31 days\n");
            break;

        case 8: printf("August has 31 days\n");
            break;

        case 9: printf("September has 30 days\n");
            break;

        case 10: printf("October has 31 days\n");
            break;

        case 11: printf("November has 30 days\n");
            break;

        case 12: printf("December has 31 days\n");
            break;

        default: printf("Invalid, enter a number between 1 and 12 only\n");
            break;
    }

return 0;
}
