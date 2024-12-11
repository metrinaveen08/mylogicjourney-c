#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    char isbn[20];
    int available; // 1 if available, 0 if borrowed
} Book;

void addBook(Book library[], int *count);
void viewBooks(Book library[], int count);
void searchBook(Book library[], int count);
void borrowBook(Book library[], int count);
void returnBook(Book library[], int count);

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                viewBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                borrowBook(library, count);
                break;
            case 5:
                returnBook(library, count);
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]%*c", library[*count].title);
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", library[*count].author);
    printf("Enter book ISBN: ");
    scanf("%s", library[*count].isbn);
    library[*count].available = 1; // Book is available when added

    (*count)++;
    printf("Book added successfully!\n");
}

void viewBooks(Book library[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Author: %s, ISBN: %s, Available: %s\n", library[i].title, library[i].author, library[i].isbn, library[i].available ? "Yes" : "No");
    }
}

void searchBook(Book library[], int count) {
    char title[100];
    printf("Enter book title to search: ");
    scanf(" %[^\n]%*c", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found: Title: %s, Author: %s, ISBN: %s, Available: %s\n", library[i].title, library[i].author, library[i].isbn, library[i].available ? "Yes" : "No");
            return;
        }
    }

    printf("Book not found.\n");
}

void borrowBook(Book library[], int count) {
    char title[100];
    printf("Enter book title to borrow: ");
    scanf(" %[^\n]%*c", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].available) {
                library[i].available = 0;
                printf("You have successfully borrowed the book: %s\n", library[i].title);
            } else {
                printf("Sorry, the book is currently borrowed.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

void returnBook(Book library[], int count) {
    char title[100];
    printf("Enter book title to return: ");
    scanf(" %[^\n]%*c", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (!library[i].available) {
                library[i].available = 1;
                printf("You have successfully returned the book: %s\n", library[i].title);
            } else {
                printf("The book was not borrowed.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}