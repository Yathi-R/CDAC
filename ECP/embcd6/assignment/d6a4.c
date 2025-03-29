/*Define a structure Course with members courseName (string of 100 characters) and
credits (integer). Define another structure Student with name (string of 50 characters),
age (integer), and an array of Course structures. Write a function to print the details of
a Student including all the courses they are enrolled in.*/

#include <stdio.h>
#include <string.h>

// Defining the Course structure
struct Course {
    char courseName[100];
    int credits;
};

// Defining the Student structure
struct Student {
    char name[50];
    int age;
    struct Course courses[5];  // maximum of 5 courses
    int numCourses;
};

// Function to print details of a student and their courses
void printStudentDetails(struct Student student) {

    // Prints the students basic information
    printf("\nStudent Name: %s\n", student.name);
    printf("Age: %d\n", student.age);

    // Print the details of the courses they are enrolled in
    printf("Courses Enrolled: %d\n", student.numCourses);
    for (int i = 0; i < student.numCourses; i++) {

        printf("Course Name: %s\n", student.courses[i].courseName);
        printf("Credits: %d\n", student.courses[i].credits);
    }
}

int main() {
    
    struct Student student1;

    // Input student's details
    printf("Enter student's name: ");
    fgets(student1.name, sizeof(student1.name), stdin);  // Using fgets to get the name

    // Removing newline character from the name input manually
    if (student1.name[strlen(student1.name) - 1] == '\n') {

        student1.name[strlen(student1.name) - 1] = '\0';
    }

    printf("Enter age: ");
    scanf("%d", &student1.age);

    // Input the number of courses
    printf("Enter number of courses enrolled in [MAX 5]: ");
    scanf("%d", &student1.numCourses);

    // Input course details
    for (int i = 0; i < student1.numCourses; i++) {

        printf("Enter course %d name: ", i + 1);
        getchar();  // To consume the leftover newline character from the previous input
        fgets(student1.courses[i].courseName, sizeof(student1.courses[i].courseName), stdin);
        
        // Removing newline character from the course name input manually
        if (student1.courses[i].courseName[strlen(student1.courses[i].courseName) - 1] == '\n') {

            student1.courses[i].courseName[strlen(student1.courses[i].courseName) - 1] = '\0';
        }

        printf("Enter credits for course %d: ", i + 1);
        scanf("%d", &student1.courses[i].credits);
    }

    // Print student's details
    printStudentDetails(student1);

    return 0;
}
