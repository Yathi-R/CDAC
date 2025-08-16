/*Write a C program to count the number of characters, words, and lines in a file*/

#include <stdio.h>
#include <ctype.h>

//Function to count number of char, words and lines in a file
void countFileStats(FILE *file, int *charCount, int *wordCount, int *lineCount) {

    *charCount = *wordCount = *lineCount = 0;
    char ch;

    // char prev = ' ';
    int inWord = 0;

    //reading char by char from file
    while ((ch = fgetc(file)) != EOF) {
        (*charCount)++; // counting each character

        if (ch == '\n') {
            (*lineCount)++; //counting line in the file
        }
        
        //counting words
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            (*wordCount)++;
        }
    
        // if (!isspace(ch) && isspace(prev)) {
        //     (*wordCount)++;
        // }

        // prev = ch; // Store current character as previous for next iteration
    }
}

int main() {
    
    //opening file named sample.txt and checking
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount, wordCount, lineCount;

    //fun calling
    countFileStats(file, &charCount, &wordCount, &lineCount);

    //closing the file
    fclose(file);

    //Printing the count
    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);

    return 0;
}
