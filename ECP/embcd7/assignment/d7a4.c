/*Write functions to initialize and print details of an Employee and a Manager.
Demonstrate the use of these functions in main.*/

#include <stdio.h>
#include <string.h>

// Defining the Employee struct
typedef struct {
    char name[100];
    int id;
    double salary;
} Employee;

// Defining the Manager struct and including Employee Struct
typedef struct {
    Employee emp;
    char department[50];
} Manager;

// Function to initialize an Employee
void initializeEmployee(Employee *emp, const char *name, int id, double salary) {

    strncpy(emp->name, name, sizeof(emp->name) - 1); // Copying name to the struct
    emp->name[sizeof(emp->name) - 1] = '\0'; //null termination
    emp->id = id;
    emp->salary = salary;
}

// Function to initialize a Manager
void initializeManager(Manager *mgr, const char *name, int id, double salary, const char *department) {

    initializeEmployee(&mgr->emp, name, id, salary);

    strncpy(mgr->department, department, sizeof(mgr->department) - 1);
    mgr->department[sizeof(mgr->department) - 1] = '\0'; //null termination
}

// Function to print details of an Employee
void printEmployeeDetails(Employee emp) {

    printf("Employee Name: %s\n", emp.name);
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Salary: %.2f\n", emp.salary);
}

// Function to print details of a Manager
void printManagerDetails(Manager mgr) {

    printf("Manager Name: %s\n", mgr.emp.name);
    printf("Manager ID: %d\n", mgr.emp.id);
    printf("Manager Salary: %.2f\n", mgr.emp.salary);
    printf("Department: %s\n", mgr.department);
}

int main() {
    Employee emp1;
    Manager mgr1;

    // Function call to initialize employee details
    initializeEmployee(&emp1, "Yathi", 101, 50000.0);
    
    // Function call to initialize manager details
    initializeManager(&mgr1, "Soniya", 102, 75000.0, "HR");

    // Function call to print employee details
    printf("Employee Details:\n");
    printEmployeeDetails(emp1);

    // Function call to print Manager details
    printf("\nManager Details:\n");
    printManagerDetails(mgr1);

    return 0;
}
