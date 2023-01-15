#include <string.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/customer.h"
#include "../include/checksum.h"
#include "../include/linkedlist.h"

/**
 * @brief Compare a regular expression pattern against a given string
 * @param pattern A regular expression pattern to compare against
 * @param string The string to compare the pattern against
 * @return 0 if a match is found, otherwise non-zero
 *
 * This function uses the POSIX regular expression library to match a
 * given regular expression pattern against a given string.
 */
int compareExpression(const char * pattern, const char * string) {
    int match_found = 0;
    int compile_reg_pattern;
    regex_t re;

    compile_reg_pattern = regcomp(&re, pattern, REG_EXTENDED);
    match_found = regexec(&re, string, 0, NULL, 0);

    regfree(&re);

    return match_found;
}


/**
 * Function that checks if a given phone number is valid.
 * @param phone_number - The phone number to be validated
 * @return int - 1 if valid, 0 if not valid
 */
int isPhoneNumberValid(char * phone_number) {
    char * pattern_1 = "^\\([0-9]{3}\\)\\s?[0-9]{3}-[0-9]{4}$";
    char * pattern_2 = "^\\+?[0-9]{9,10}$";

    int test_1 = compareExpression(pattern_1, phone_number);
    int test_2 = compareExpression(pattern_2, phone_number);

    if (test_1 == 0 || test_2 == 0)
        return 1;  // A valid phone number was found.

    return 0;      // No valid phone number was found.
}

/**
 * @brief Prints customer details to console.
 */
void showCustomerDetails(Customer * customer) {
    printf("ID: %s\n", customer->id);
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Phone Number: %s\n", customer->phone_number);
}

/**
 * Initializes a Customer struct with the given information.
 *
 * @param this         Pointer to the Customer struct to be initialized
 * @param name         Name of the customer
 * @param address      Address of the customer
 * @param phone_number Phone number of the customer
 */
void Customer_init(Customer * this, char * name,
                   char * address, char * phone_number) {

    if (isPhoneNumberValid(phone_number)) {
        strcpy(this->name, name);
        strcpy(this->address, address);
        strcpy(this->phone_number, phone_number);
        this->books_checked_out = (struct LinkedList *) malloc(sizeof (struct LinkedList));
        this->num_books_checked_out = 0;

        char hash_input[100];
        strcat(hash_input, name);
        strcat(hash_input, address);
        char * id = md5(hash_input);

        strcpy(this->id, id);

    } else {
        fprintf(stderr,
                "Invalid phone number entered: (%s, %s, %s)",
                name, address, phone_number);
        exit(1);
    }
}