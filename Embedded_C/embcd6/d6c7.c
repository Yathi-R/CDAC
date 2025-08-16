/*Array of structure*/

#include<stdio.h>
#include<string.h>

struct student {
    int roll_no;
    float marks[5];
    char name[30];
} stud[3];

int main(){

    for (int x = 0; x < 3; x++){

        printf("Enter %d student name, roll_no: ", x+1);
        scanf("%s %d", stud[x].name, &stud[x].roll_no);

        for(int i = 0; i < 5; i++){
            printf("Enter student %s %d subject marks: ", stud[x].name, i+1);
            scanf("%f", &stud[x].marks[i]);
        }
    }
    
    printf("\nStudent Details:\n");
    for (int x = 0; x < 3; x++) {
        printf("\nStudent %d:\n", x + 1);
        printf("Name: %s\n", stud[x].name);
        printf("Roll No: %d\n", stud[x].roll_no);
        printf("Marks: ");
        for (int i = 0; i < 5; i++) {
            printf("%.2f ", stud[x].marks[i]);
        }
        printf("\n");
    }

    return 0;
}