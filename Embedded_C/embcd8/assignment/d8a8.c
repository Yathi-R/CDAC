/*Write a C program to merge the contents of multiple text files into a single file*/

#include <stdio.h>

int main(){

    int noFile;

    //getting user input for num of source files to merge
    printf("Enter the number of file to merge: ");
    scanf("%d", &noFile);

    //array of file pointers 
    FILE *inFile[noFile], *outFile;

    char ch, srcFile[50], desFile[50];

    //getting output file name
    printf("Enter the output file name(No space): ");
    scanf("%s", desFile);

    //Opening output file
    outFile = fopen(desFile, "w");

    //checking is file opened or not
    if( outFile == NULL){
        perror("Error opening file:");
        return 1;
    }

    //getting source file name and reading and appedning to outputfile
    for (int i = 0; i < noFile; i++){

        //getting source file name
        printf("Enter the input file name %d: ", i+1);
        scanf("%s", srcFile);

        //opening source file
        inFile[i] = fopen(srcFile, "r");
        if( inFile[i] == NULL){
            perror("Error opening file:");
            fclose(outFile);
            return 1;
        }

        //reading source and appending to outputfile
        while ((ch = fgetc(inFile[i]) )!= EOF){
            fputc(ch, outFile);
        }

        //closing source file
        if( fclose(inFile[i]) != 0){
            perror("Error closing input file:");
            fclose(outFile);
            return 1;
        }
    }

    //closing output file
    if ( fclose(outFile) != 0){
        perror("Error closing output file:");
        return 1;
    }

    printf("Files merged successfully into %s\n", desFile);

    return 0;
}