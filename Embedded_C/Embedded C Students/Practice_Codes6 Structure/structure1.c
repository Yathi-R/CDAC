#include<stdio.h>

// struct data type declarartion
struct student
{
    int rollno;         // 4 bytes
    char name[20];      // 20 bytes
    float marks;        // 4 bytes
};                      // 28 bytes

int main(void)
{
    struct student st1;
    struct student st2 = {11, "devendra", 65.0f};
    struct student st3 = {
        .name = "nilesh",
        .rollno = 11,
        .marks = 70.0f
    };// tagged init

    printf("%d %s %f\n", st1.rollno, st1.name, st1.marks); 
    printf("%d %s %f\n", st2.rollno, st2.name, st2.marks);
    printf("%d %s %f\n", st3.rollno, st3.name, st3.marks);    

    printf("sizeof(st1) = %d\n", sizeof(st1));
    printf("sizeof(struct student) = %d\n", sizeof(struct student));


    printf("ENter student info : (rollno, name, marks) :: ");
    scanf("%d %[^\n]s %f", &st1.rollno, st1.name, &st1.marks);

    printf("%d %s %f\n", st1.rollno, st1.name, st1.marks);   
    return 0;
}