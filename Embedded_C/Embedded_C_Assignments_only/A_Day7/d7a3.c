/*Write a function to initialize a Book struct with a title and publication date. Then print the details
of the book in main.*/

#include <stdio.h>
#include <string.h>

// Date struct to hold day, month, and year
typedef struct {
    int day;
    int month;
    int year;
}Date;

// Book struct which contains a title and a Date struct
typedef struct {
    char title[100];
    Date publicationDate;
}Book;

// Function to initialize the Book struct
void initializeBook(Book *book, const char *title, int day, int month, int year) {

    strncpy(book->title, title, sizeof(book->title) - 1); // Copying title to the struct
    book->title[sizeof(book->title) - 1] = '\0'; // null termination at the end
    book->publicationDate.day = day;
    book->publicationDate.month = month;
    book->publicationDate.year = year;
}

int main() {
    Book myBook;

    // Initializing the book with a title and a publication date
    initializeBook(&myBook, "Master Embedded C", 24, 2, 1997);

    // Printing the details of the book
    printf("Book Title: %s\n", myBook.title);
    printf("Publication Date: %02d-%02d-%d\n", myBook.publicationDate.day, myBook.publicationDate.month, myBook.publicationDate.year);

    return 0;
}
