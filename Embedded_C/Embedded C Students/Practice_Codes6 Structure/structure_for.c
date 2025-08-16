#include<stdio.h>

typedef struct employee{
    int empid;
    char name[20];
    double salary;
}emp_t;

  
int main(void)
{
    emp_t list[4];
    
    for(int i = 0 ; i < 4 ; i++)
    {
        printf("Enter %d emp info : (empid, name, salary) :: ", i+1);
        scanf("%d %s %lf", &list[i].empid, list[i].name, &list[i].salary);
    }

    for(int i = 0 ; i < 4 ; i++)
        printf("%-4d %-20s %-0.2lf\n", list[i].empid, list[i].name, list[i].salary);


    return 0;
}