#include<stdio.h>

struct student{
    int rollno;
    char name[20];
    float marks;
};

typedef struct student stud_t;

int main(void)
{
    stud_t st2 = {11, "devendra", 65.00f};
    stud_t *pst = &st2;
    // pointer to struct variable

    printf("%d %s %f\n", pst->rollno, pst->name, pst->marks);

    return 0;
}