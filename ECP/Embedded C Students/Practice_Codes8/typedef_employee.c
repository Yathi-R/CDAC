#include <stdio.h>
#include <string.h>

// Define the typedefs for Employee and Manager
typedef struct {
    int id;
    char name[50];
} Employee;

typedef struct {
    Employee emp;  // Employee part
    float salary;  // Additional Manager part
} Manager;

// Function to initialize an Employee
void initializeEmployee(Employee* e, int id, const char* name) {
    e->id = id;
    strncpy(e->name, name, sizeof(e->name) - 1);
    e->name[sizeof(e->name) - 1] = '\0';  // Ensure null termination
}

// Function to print details of an Employee
void printEmployee(const Employee* e) {
    printf("Employee ID: %d\n", e->id);
    printf("Employee Name: %s\n", e->name);
}

// Function to initialize a Manager
void initializeManager(Manager* m, int id, const char* name, float salary) {
    initializeEmployee(&m->emp, id, name);  // Initialize the Employee part
    m->salary = salary;  // Set the salary for the Manager
}

// Function to print details of a Manager
void printManager(const Manager* m) {
    printEmployee(&m->emp);  // Print the Employee part
    printf("Manager Salary: %.2f\n", m->salary);
}

int main() {
    // Create and initialize an Employee
    Employee emp1;
    initializeEmployee(&emp1, 101, "Alice Johnson");
    
    // Create and initialize a Manager
    Manager mgr1;
    initializeManager(&mgr1, 202, "Bob Smith", 75000.00);
    
    // Print details
    printf("Employee Details:\n");
    printEmployee(&emp1);
    
    printf("\nManager Details:\n");
    printManager(&mgr1);
    
    return 0;
}