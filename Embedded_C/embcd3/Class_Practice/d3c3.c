/*To find leap year*/

#include<stdio.h>

int main(){

    int year;

    printf("Enter a year in yyyy format: ");
    scanf("%d", &year);                              /*Gets year from user*/

    
    if(year>0){

        /*checks if year is (div by 4 & not by 100) or div by 400 */
        if((year%4==0 && year%100 != 0) || year%400 ==0){ 
            printf("%d is a Leap year\n", year);
        }

        else{
            printf("%d isn't a Leap Year\n", year);
        }
    }
    else{
        printf("Year can't be negative or zero\n");
    }

return 0;
}