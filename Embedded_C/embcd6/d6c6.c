#include<stdio.h>
#include<string.h>

struct person {
    struct date {
        int date;
        int month;
        int year;
    } dob;
    int roll_no;
    char name[30];
} p1;

int main(){
    
    p1.dob.date = 04;
    p1.dob.month = 07;
    p1.dob.year = 1991;

    strcpy(p1.name, "yathi");
    p1.roll_no = 12345;
    
    printf("Name: %s\n", p1.name);
    printf("Roll no: %d\n", p1.roll_no);
    printf("DOB: %d/%d/%d\n", p1.dob.date, p1.dob.month, p1.dob.year);

    return 0;
}

