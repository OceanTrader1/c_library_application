/**
 * @file customer.h
 * @brief Header file for customer management
 *
 * This file contains the declarations for functions and
 * structures used for customer management in a library
 * system. The functions include creating a new customer,
 * displaying customer details, validating customer phone
 * number and phone expression validation.
 *
 */

#ifndef LIBRARY_CUSTOMER_H
#define LIBRARY_CUSTOMER_H
#endif

typedef struct Customer {
    char id[100];
    char name[100];
    char address[100];
    char phone_number[12];
    struct LinkedList * books_checked_out;
    int num_books_checked_out;
} Customer;

void Customer_init(struct Customer * customer, char * name,
                   char * address, char * phone_number);

void showCustomerDetails(Customer * customer);

void getPhoneNumberDigitsOnly(char * phone_number);

int isPhoneNumberValid(char * phone_number);

int isPhoneExpressionValid(const char * pattern, const char * string);
