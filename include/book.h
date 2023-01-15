/**
 *  book.h
 *
 *  @brief Book struct is used to store the information of a Book.
 *  The struct includes information such as book's title, ISBN, publish year, and checkout status.
 *
 *  id - unique identifier for the book
 *  title - title of the book
 *  isbn - International Standard Book Number of the book
 *  publish_year - the year the book was published
 *  checkout_status - the current status of the book, whether it is on shelf or checked out
 *  return_date - the date the book is due to be returned
 */

#include "date.h"
#include "linkedlist.h"

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#endif


typedef struct Book {
    char id[100];
    char title[100];
    int  isbn;
    int  publish_year;
    int  checkout_status;  // 0 = On shelf; 1 = Checked out
    Date return_date;
} Book;

void Book_init(Book * this, char * title, int isbn, int publish_year);

void printBook(Book book);

typedef struct Customer Customer;

void checkoutBook(Book * book, Customer * customer);

void returnBook(Book * book, Customer * customer);