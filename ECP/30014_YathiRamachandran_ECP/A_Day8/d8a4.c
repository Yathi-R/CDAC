/*Write a C program to create a file and write user input into it.*/

/*Creating file and writing user input data into it*/

#include<stdio.h>

int main(){
    
    FILE *file;

    //char array to store user input
    char text[200];

    //Opening file with write mode
    file = fopen("output.txt", "w");

    //checking if file creation/opening is successfull or not
    if(file == NULL){
        perror("Error opening file.\n");
        return 1;
    }

    //Getting user input
    printf("Enter text to store in the output.txt file: ");
    fgets(text, sizeof(text), stdin);

    //Writting text to the file
    fprintf(file, "%s", text);

    //closing and checking if its successfull
    if(fclose(file) != 0){
        perror("Error closing file: \n");
        return 1;
    }

    return 0;
}