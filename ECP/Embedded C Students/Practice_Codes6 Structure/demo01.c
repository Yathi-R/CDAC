#include<stdio.h>

int main(void)
{
    int roll_no;
    char name[20];
    float marks;

    printf("Enter student info : (roll no, name, marks) :: ");
    scanf("%d %s %f", &roll_no, name, &marks);

    printf("%d %s %f\n", roll_no, name, marks);

    return 0;
}