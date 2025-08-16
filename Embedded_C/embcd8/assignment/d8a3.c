/*Write a C program to read the contents of a file and display it on the screen.*/

#include<stdio.h>

int main(){

    char ch;

    //Opening a file using file pointer with read only mode
    FILE *file = fopen("sample.txt", "r");

    //checking if file opening is successfull or not
    if (file == NULL){
        perror("Error opening file:\n");
        return 1;
    }

    //reading char by char in the file and displaying it
    while ((ch = fgetc(file)) != EOF){
        putchar(ch);
    }

    //closing the file
    fclose(file);

    return 0;
}