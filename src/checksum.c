#include <openssl/sha.h>
#include <openssl/md5.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/checksum.h"


//void sha256(unsigned char * string, unsigned char * hash) {
//    SHA256(string, strlen((char *) string), hash);
//}

/**
 *
 * @brief Returns the SHA-256 hash of a given string
 *
 * This function calculates the SHA-256 hash of the input string, and
 * returns the result as a string of hexadecimal characters.
 *
 * @param string input string to be hashed
 *
 * @return a string containing the SHA-256 hash of the input string
 *
 * @warning The returned string is allocated using malloc and it is the
 * responsibility of the caller to free it.
 * @warning The function doesn't check for invalid input, if the input
 * is NULL or empty the function will return undefined behavior.
 *
 * @example
 *  char * hashed = sha256("Hello World");
 *  printf("%s\n", hashed);
 *
 * Output:
 *  a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e
 *
 */
char * sha256(const char * string) {
    /* Returns the SHA256 hash of a string. */
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char * result = malloc(2 * SHA256_DIGEST_LENGTH + 1);

    SHA256((const unsigned char *)string, strlen((char *) string), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&result[i * 2], "%02x", (unsigned int)hash[i]);
    }

    return result;
}


//void md5(unsigned char * string, unsigned char * hash) {
//    MD5(string, strlen((char *) string), hash);
//}

/**
 *
 * @brief Returns the MD5 hash of a given string
 *
 * This function calculates the MD5 hash of the input string, and returns
 * the result as a string of hexadecimal characters.
 *
 * @param string input string to be hashed
 *
 * @return a string containing the MD5 hash of the input string
 *
 * @warning The returned string is allocated using malloc and it is the
 * responsibility of the caller to free it.
 * @warning The function doesn't check for invalid input, if the input
 * is NULL or empty the function will return undefined behavior.
 * @warning MD5 is considered a weak cryptographic hash function and should
 * be avoided in favor of a more secure option, such as SHA-256.
 *
 * @example
 *  char * hashed = md5("Hello World");
 *  printf("%s\n", hashed);
 *
 * Output:
 *  b10a8db164e0754105b7a99be72e3fe5
 *
 */
char * md5(const char * string) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    char * result = malloc(2 * MD5_DIGEST_LENGTH + 1);

    MD5((const unsigned char *)string, strlen((char *) string), hash);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&result[i * 2], "%02x", (unsigned int)hash[i]);
    }

    return result;
}