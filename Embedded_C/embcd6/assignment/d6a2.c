/*Define a structure Person with the members name (string of 50 characters) and age
(integer). Write a program to initialize a Person structure with your own details and
then print the name and age of the person.*/

/* Struct person with name and age*/

#include<stdio.h>
#include<string.h>

// Structure with 2 members name and age
struct Person {
    char name[50];
    int age;
};

int main(){

    //Initializing the name and age
    struct Person p1 = {"Yathi", 30};
    
    //Printing the name and age in structure person
    printf("My name is %s\n", p1.name);
    printf("My age is %d\n", p1.age);
    
    return 0;
}