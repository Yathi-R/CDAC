#include<stdio.h>

int main(void)
{
    int roll_no[10];
    char name[10][20];
    float marks[10];

    printf("Enter student1 info : (roll no, name, marks) :: ");
    scanf("%d %s %f", &roll_no[0], name[0], &marks[0]);

    printf("Enter student2 info : (roll no, name, marks) :: ");
    scanf("%d %s %f", &roll_no[1], name[1], &marks[1]);

    printf("Enter student3 info : (roll no, name, marks) :: ");
    scanf("%d %s %f", &roll_no[2], name[2], &marks[2]);

    printf("%d %s %f\n", roll_no[0], name[0], marks[0]);
    printf("%d %s %f\n", roll_no[1], name[1], marks[1]);
    printf("%d %s %f\n", roll_no[2], name[2], marks[2]);

    return 0;
}