#include <stdio.h>
int main() {
    // Open file for writing
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    // Write to the file
    fprintf(file, "Hello, How are you at CDAC!\n");
    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }
// Open file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    // Read from the file
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read from file: %s", buffer);
    }
    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }
    return 0;		
}
