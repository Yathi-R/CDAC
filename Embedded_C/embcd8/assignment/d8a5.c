/*C program to append text to an existing file.*/

#include<stdio.h>

int main(){

    FILE *file; // file pointer

    // char array to get user input
    char text[100];

    //opening existing file with append mode
    file = fopen("output.txt", "a");

    //checking if file opening is succedded
    if (file == NULL){
        perror("Error opening file: \n");
        return 1;
    }

    //getting user text input
    printf("Enter text to append to output.txt file: ");
    fgets(text, sizeof(text), stdin);

    //writting text to file
    fprintf(file, "%s", text);

    //closing and checking if file is closed or not
    if((fclose(file) != 0)){
        perror("Error closing file: \n");
        return 1;
    }
    
    return 0;
}