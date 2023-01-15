/**
 * date.h
 *
 * @brief This file contains the declarations for functions that handle date operations.
 *
 * The functions in this file are used to create and manipulate Date objects,
 * which are structs that represent a date in the format of year, month, and day.
 *
 * Functions:
 *    Date_init: Initializes a Date object with a given year, month, and day.
 *    daysBetweenDates: Calculates the number of days between two given dates.
 *    getCurrentYear: Returns the current year as an integer.
 *    getCurrentMonth: Returns the current month as an integer (1-12).
 *    getCurrentDay: Returns the current day as an integer (1-31).
 *    getCurrentDate: Returns a Date object representing the current date.
 *    printDate: Prints the date in the format of "year/month/day" to the console.
 */

#include <time.h>

#include "checksum.h"

#ifndef LIBRARY_DATE_H
#define LIBRARY_DATE_H
#endif

typedef struct tm Date;

void Date_init(Date * this, int year, int month, int day);

int daysBetweenDates(Date date1, Date date2);

int getCurrentYear();

int getCurrentMonth();

int getCurrentDay();

Date getCurrentDate();

void printDate(Date date);