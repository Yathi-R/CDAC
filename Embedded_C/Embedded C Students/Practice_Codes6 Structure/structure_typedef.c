#include<stdio.h>

// employee
// empid, name, address, emailid, dob, designation, doj, salary

typedef struct date{
    int dd;
    int mm;
    int yyyy;
}date_t;

typedef struct person{
    char name[20];
    char address[20];
    char email[20];
}person_t;

typedef struct employee{
    int empid;
    person_t personal_info;
    date_t dob;
    char designation[20];
    date_t doj;
    double salary;
}emp_t;

void accept_date(date_t *);
void accept_personal_info(person_t *);
void accept_emp(emp_t *);
void print_date(date_t *);
void print_personal_info(person_t *);
void print_emp(emp_t *);

int main(void)
{
    emp_t emp;

    accept_emp(&emp);
    print_emp(&emp);

    return 0;
}

void accept_date(date_t *dt)
{
    printf("dd, mm, yyyy : ");
    scanf("%d %d %d", &dt->dd, &dt->mm, &dt->yyyy);
}
void accept_personal_info(person_t *p)
{
    printf("name, address, email : ");
    scanf("%s %s %s", p->name, p->address, p->email);
}

void accept_emp(emp_t *emp)
{
    printf("Enter Employee info : \n");
    printf("Empid : ");
    scanf("%d", &emp->empid);

    printf("Personal Info : ");
    accept_personal_info(&emp->personal_info);

    printf("Date of birth : ");
    accept_date(&emp->dob);

    printf("Designation : ");
    scanf("%s", emp->designation);

    printf("Date of joining : ");
    accept_date(&emp->doj);

    printf("Salary : ");
    scanf("%lf", &emp->salary);

}

void print_date(date_t *dt)
{
    printf("%d/%d/%d\n", dt->dd, dt->mm, dt->yyyy);
}
void print_personal_info(person_t *p)
{
    printf("Name  - %s\n", p->name);
    printf("Address - %s\n", p->address);
    printf("Email - %s\n", p->email);
}
void print_emp(emp_t *emp)
{
    printf("Empid - %d\n", emp->empid);
    printf("Personal Info : \n");
    print_personal_info(&emp->personal_info);
    printf("DOB : ");
    print_date(&emp->dob);
    printf("Designation - %s\n", emp->designation);
    printf("DOJ : ");
    print_date(&emp->doj);
    printf("Salary - %lf\n", emp->salary);
}