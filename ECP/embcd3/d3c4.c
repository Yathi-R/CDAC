/*using Switch condition to get weekdays and months in the year*/

#include<stdio.h>

int main(){

    int n, day, month;

    printf("To check Day enter 0 and for Month enter 1:");
    scanf("%d", &n);

    /*To find days in the week*/
    if (n == 0){

        printf("Enter a number from to 1 to 7:");
        scanf("%d", &day);

        switch(day){
            case 1: printf("The day is Sunday\n");
                break;
            case 2: printf("The day is Monday\n");
                break;
            case 3: printf("The day is Tuesday\n");
                break; 
            case 4: printf("The day is Wednesday\n");
                break; 
            case 5: printf("The day is Thurday\n");
                break;
            case 6: printf("The day is Friday\n");
                break; 
            case 7: printf("The day is Saturday\n");
                break;
            default: printf("Invalid number\n");
                break;
        }

    }
    /*To find month in the year*/
    else if (n==1){

        printf("Enter a number from to 1 to 12:");
        scanf("%d", &month);

        switch(month){
            case 1: printf("The month is January\n");
                break;
            case 2: printf("The month is February\n");
                break;
            case 3: printf("The month is March\n");
                break; 
            case 4: printf("The month is April\n");
                break; 
            case 5: printf("The month is May\n");
                break;
            case 6: printf("The month is June\n");
                break; 
            case 7: printf("The month is July\n");
                break;
            case 8: printf("The month is August\n");
                break; 
            case 9: printf("The month is September\n");
                break; 
            case 10: printf("The month is October\n");
                break;
            case 11: printf("The month is November\n");
                break; 
            case 12: printf("The month is December\n");
                break;
            default: printf("Invalid number\n");
                break;
        }
    }

    else{
        printf("Invalid number\n");
    }
    
return 0;
}