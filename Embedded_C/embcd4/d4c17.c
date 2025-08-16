/* Program to calculate BMI*/

#include<stdio.h>

int main(){

    char name[30];

    int age; 
    float height, weight, bmi;
    
    printf("Enter your name: ");
    fgets(name, 30, stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    //getting persons height and weight
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    
    printf("Enter your weight in kilogram: ");
    scanf("%f", &weight);

    //input validation
    if (height <= 0 || weight <= 0){
        printf("Invalid height or weight\n");
        return 1;
    }

    //calculating BMI
    bmi = weight / (height * height);

    printf("Hello %sYour BMI is %0.2f\n", name, bmi);

    //Displaying BMI of the person
    if( bmi >= 28.5){
        printf("Your BMI indicates you are \"Obese\", please get health care\n");
    }
    else if (bmi<=18.5){
        printf("Your BMI indicates you are \"Under Weight\", please consult a dietician\n");
    }
    else if (bmi >=25 && bmi < 28.5){
        printf("Your BMI indicates you are \"Over Weight\", please watch your diet and check if any health condition exist\n");
        }
    else {
        printf("Your BMI is in \"correct range\", please maintain it\n");
    }

return 0;
}