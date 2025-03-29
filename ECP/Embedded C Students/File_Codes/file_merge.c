#include <stdio.h>
#include <stdlib.h>

void mergeFiles(const char *outputFileName, int numFiles, const char *fileNames[]) {
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    for (int i = 0; i < numFiles; i++) {
        FILE *inputFile = fopen(fileNames[i], "r");
        if (inputFile == NULL) {
            perror("Error opening input file");
            continue;
        }

        fprintf(outputFile, "\n--- Start of %s ---\n", fileNames[i]);
        while (fgets(buffer, sizeof(buffer), inputFile)) {
            fputs(buffer, outputFile);
        }
        fprintf(outputFile, "\n--- End of %s ---\n", fileNames[i]);

        fclose(inputFile);
    }

    fclose(outputFile);
}

int main() {
    const char *fileNames[] = {"file1.txt", "file2.txt", "file3.txt"};
    mergeFiles("merged.txt", sizeof(fileNames) / sizeof(fileNames[0]), fileNames);
    return 0;
}