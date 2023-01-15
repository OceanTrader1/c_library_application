#include <stdio.h>

#include "../include/customer.h"
#include "../include/date.h"
#include "../include/book.h"

void clear_screen() {
    printf("\033[H\033[J");
}

int main() {
    struct Customer john, sally, tom;

    Customer_init(&john, "John Hoover", "123 I live here", "(123) 456-1234");
    Customer_init(&sally, "Sally Grover", "356 Home on the range", "(123) 456-1233");
    Customer_init(&tom, "Tom Zanicki", "789 Over the Rainbow", "(123) 456-1233");

    struct Customer customers[] = {john, sally, tom};
    int num_customers = (int) (sizeof customers / sizeof customers[0]);

    struct Book give_a_mouse_a_cookie,
                give_a_moose_a_muffin,
                give_a_pig_a_pancake;

    Book_init(&give_a_mouse_a_cookie, "If you give a mouse a cookie", 12345689, 2002);
    Book_init(&give_a_moose_a_muffin, "If you give a moose a muffin", 45669239, 2004);
    Book_init(&give_a_pig_a_pancake, "If you give a pig a pancake", 87234618, 2006);

    struct Book books[] = {give_a_mouse_a_cookie,
                           give_a_moose_a_muffin,
                           give_a_pig_a_pancake};
    int num_books = (int) (sizeof books / sizeof books[0]);

    printBook(give_a_mouse_a_cookie);

    checkoutBook(&give_a_mouse_a_cookie, &john);

    printBook(give_a_mouse_a_cookie);

    returnBook(&give_a_mouse_a_cookie, &john);

    checkoutBook(&give_a_moose_a_muffin, &sally);


    return 0;
}
