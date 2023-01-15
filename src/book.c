#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/customer.h"
#include "../include/book.h"


/**
 * @brief Initializes a Book object with a given title, ISBN, and publish year.
 *
 * @param this pointer to the Book object that is being initialized
 * @param title title of the book
 * @param isbn ISBN of the book
 * @param publish_year the year the book was published
 */
void Book_init(Book * this, char * title, int isbn, int publish_year) {
    strcpy(this->title, title);
    this->isbn = isbn;
    this->publish_year = publish_year;
    this->checkout_status = 0;

    char tmp_a[50];
    char hash_input[100];
    sprintf(tmp_a, "%d", isbn);
    strcpy(hash_input, tmp_a);
    strcpy(hash_input, title);

    char * id = md5(hash_input);

    strcpy(this->id, id);
}


void printBook(Book book) {
    printf("ID: %s\n", book.id);
    printf("Title: %s\n", book.title);
    printf("ISBN: %d\n", book.isbn);
    printf("Year Published: %d\n", book.publish_year);
    printf("Status: %s\n", (book.checkout_status == 1 ? "Checked Out" : "On Shelf"));
}


/**
 * @brief Checkout a book for a customer.
 *
 * This function sets the checkout_status of the book to 1 and adds the book's id to the
 * customer's books_checked_out list. The function also increments the customer's
 * num_books_checked_out attribute by 1.
 *
 * @param book A pointer to the book being checked out.
 * @param customer A pointer to the customer checking out the book.
 */
void checkoutBook(Book * book, Customer * customer) {
    book->checkout_status = 1;

    if (customer->books_checked_out->head == NULL) {
        LinkedList_init(customer->books_checked_out);
    }

    int ctr = 0;
    struct Node * head = customer->books_checked_out->head;
    while (head != NULL) {
        if (strcmp(book->id, head->data) == 0) {
            // Value already exists in LinkedList
            fprintf(stderr,
                    "ERROR: checkoutBook: Book ID %s is already checked out. Cannot checkout the same book.\n",
                    book->id
            );
            exit(1);
        }
        head = head->next;
        ctr++;
    }

    addNode(customer->books_checked_out, book->id);
    customer->num_books_checked_out++;

    fprintf(stdout, "\033[32m%s checked out book '%s'.\033[0m\n", customer->name, book->title);
}


/**
 * @brief Returns a book to the library
 *
 * @param book Pointer to the book being returned
 * @param customer Pointer to the customer returning the book
 */
void returnBook(Book * book, Customer * customer) {
    book->checkout_status = 0;

    if (customer->books_checked_out == NULL) {
        fprintf(stderr, "ERROR: returnBook: %s does not have any books checked out", customer->name);
        exit(1);
    }
    removeNode(customer->books_checked_out, book->id);
    customer->num_books_checked_out--;

    fprintf(stdout, "\033[0;34m%s returned book '%s'.\033[0m\n", customer->name, book->title);
}