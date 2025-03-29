#include <stdio.h>
#include <string.h>  // For strncpy function

// Define the Book struct
typedef struct {
    char title[100];
    struct {
        int day;
        int month;
        int year;
    } publicationDate;
} Book;

// Function to initialize a Book
void initializeBook(Book* book, const char* title, int day, int month, int year) {
    // Set the title
    strncpy(book->title, title, sizeof(book->title) - 1);
    book->title[sizeof(book->title) - 1] = '\0';  // Ensure null termination
    
    // Set the publication date
    book->publicationDate.day = day;
    book->publicationDate.month = month;
    book->publicationDate.year = year;
}

// Function to print the details of a Book
void printBook(const Book* book) {
    printf("Title: %s\n", book->title);
    printf("Publication Date: %02d/%02d/%d\n",
           book->publicationDate.day,
           book->publicationDate.month,
           book->publicationDate.year);
}

int main() {
    // Create and initialize a Book
    Book myBook;
    initializeBook(&myBook, "The Great Gatsby", 10, 4, 1925);
    
    // Print the details of the book
    printBook(&myBook);
    
    return 0;
}