#include<stdio.h>

typedef struct employee
{
    int empid;          // 4
    char name[20];      // 20
    double salary;      // 8
}emp_t;                 // 32 bytes 

emp_t accept_emp(void);
void print_emp(emp_t);

int main(void)
{
    emp_t emp;

    emp = accept_emp();
    print_emp(emp);

    return 0;
}

emp_t accept_emp(void)
{
    emp_t emp;
    printf("Enter empid : ");
    scanf("%d", &emp.empid);

    printf("Enter emp name : ");
    scanf("%*c%[^\n]s", emp.name);

    printf("Enter salary : ");
    scanf("%lf", &emp.salary);

    return emp;
}
void print_emp(emp_t emp)
{
    printf("%d %s %lf\n", emp.empid, emp.name, emp.salary);
}