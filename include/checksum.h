/**
 * @file checksum.h
 *
 * @brief This file contains the declarations for functions that generate checksums for strings.
 *
 * The functions in this file are used to create a SHA-256 or MD5 checksum for a given string.
 *
 * Functions:
 *    sha256: Generates a SHA-256 checksum for the given string.
 *    md5: Generates a MD5 checksum for the given string.
 */

#ifndef LIBRARY_CHECKSUM_H
#define LIBRARY_CHECKSUM_H
#endif

char * sha256(const char * string);

char * md5(const char * string);