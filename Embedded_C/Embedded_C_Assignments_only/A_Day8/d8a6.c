/*Write a C program to copy the contents of one file to another.*/

#include<stdio.h>
#include<string.h>

int main(){

    char buffer[100];

    //File pointer
    FILE *file1, *file2;

    file1 = fopen("sample.txt", "r"); //opening file1 in read mode

    file2 = fopen("output.txt", "a"); //opening file2 in append mode

    //checking is file is opened or not
    if (file1 == NULL){
        perror("Error opening file: \n");
        return 1;
    }

    //checking is file is opened or not
    if (file2 == NULL){
        perror("Error opening file: \n");
        fclose(file1);
        return 1;
    }

    //reading each line from file 1 and appending to file 2
    while ( fgets(buffer, sizeof(buffer), file1) != NULL ) {
        fprintf(file2, "%s", buffer);
    }

    //closing the file
    if((fclose(file1) != 0)){
        perror("Error closing file: \n");
        fclose(file2);
        return 1;
    }

    //closing the file
    if((fclose(file2) != 0)){
        perror("Error closing file: \n");
        return 1;
    }

    printf("File contents copied successfully.\n");
    
    return 0;
}