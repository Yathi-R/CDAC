/*Write a C program to take information from user using structures like roll number,
name, standard and percentage. Print them as well.*/

/*Take info from user for structure and print all members*/

#include<stdio.h>

// structure names Student with 4 members
struct Student {
    int rollNo, standard;
    char name[50];
    float percentage;
} stud;

int main(){

    // taking information of structure Student
    printf("Enter the name of the student: ");
    scanf("%s", stud.name);

    printf("Enter the Roll no: ");
    scanf("%d", &stud.rollNo);

    printf("Enter the standard: ");
    scanf("%d", &stud.standard);

    printf("Enter the percentage: ");
    scanf("%f", &stud.percentage);

    // Displaying all the members in Struct Student
    printf("\nStudent details:\n");
    printf("Name: %s\n", stud.name);
    printf("Roll No: %d\n", stud.rollNo);
    printf("Standard: %d\n", stud.standard);
    printf("Percentage: %0.2f\n", stud.percentage);

    return 0;
}