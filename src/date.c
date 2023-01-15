#include <stdlib.h>
#include <stdio.h>

#include "../include/date.h"

/**
 *
 * @brief Creates a Date object.
 *
 * This function creates a Date struct by initializing its
 * year, month, day, hour, minute, second, and isdst fields.
 *
 * @param this pointer to the Date struct to be initialized
 * @param year int representing the year
 * @param month int representing the month
 * @param day int representing the day
 *
 * @example
 *  Date today;
 *  Date_init(&today,2023,1,14);
 *
 * Output:
 *  Date struct representing the 14th of January, 2023
 *
 */
void Date_init(Date * this, int year, int month, int day) {
    this->tm_year = year - 1900;
    this->tm_mon = month - 1;
    this->tm_mday = day;
    this->tm_hour = 0;
    this->tm_min = 0;
    this->tm_sec = 0;
    this->tm_isdst = -1;  // -1 means the information is not available;
}

/**
 *
 * @brief Calculates the difference between two dates in number of days
 *
 * This function calculates the difference in days between two given dates by using the mktime() and difftime() functions.
 *
 * @param date1 the first date
 * @param date2 the second date
 *
 * @return the difference in days between date2 and date1
 *
 * @example
 *  Date date1;
 *  date1 = getCurrentDate();
 *  Date date2;
 *  date2 = getFutureDate(date1, 10);
 *  int days = daysBetweenDates(date1, date2);
 *
 * Output:
 *  10
 *
 */
int daysBetweenDates(Date date1, Date date2) {
    /* Returns the difference between date1 and date2
     * in number of days (date2 - date1).
     */
    time_t d1 = mktime(&date1);
    time_t d2 = mktime(&date2);

    double diff = difftime(d2, d1) / (24 * 60 * 60);

    return (int) diff;
}


int getCurrentYear() {
    /* Returns the current year. */
    char year[50];
    time_t today;
    struct tm * local_time;

    time(&today);
    local_time = localtime(&today);
    strftime(year, sizeof(year), "%Y", local_time);

    return atoi(year);
}


int getCurrentMonth() {
    /* Returns the current month */
    char month[50];
    time_t today;
    struct tm * local_time;

    time(&today);
    local_time = localtime(&today);
    strftime(month, sizeof(month), "%m", local_time);

    return atoi(month);
}


int getCurrentDay() {
    /* Returns the current day */
    char day[50];
    time_t today;
    struct tm * local_time;

    time(&today);
    local_time = localtime(&today);
    strftime(day, sizeof(day), "%d", local_time);

    return atoi(day);
}

/**
 *
 * @brief Returns the current date.
 *
 * This function returns a Date struct representing the current date,
 * obtained by calling getCurrentDay(), getCurrentMonth(), and getCurrentYear()
 * functions.
 *
 * @return Date struct representing the current date.
 *
 * @example
 * Date today = getCurrentDate();
 *
 * Output:
 *  Date struct representing the current date.
 *
 */
Date getCurrentDate() {
    Date today;
    int month, day, year;

    day = getCurrentDay();
    month = getCurrentMonth();
    year = getCurrentYear();

    Date_init(&today, year, month, day);
    return today;
}

/**
 *
 * @brief Prints date information to console.
 *
 * This function takes a Date struct as an argument, and prints the date, year, month, and day
 * of the date to the console.
 *
 * @param date The date to be printed.
 *
 * @example
 * Date today;
 * today = getCurrentDate();
 * printDate(today);
 *
 * Output:
 *  Date: 1/14/2023
 *  Year: 2023
 *  Month: 1
 *  Day: 14
 *
 */
void printDate(Date date) {
    int year, month, day;

    year = date.tm_year + 1900;
    month = date.tm_mon + 1;
    day = date.tm_mday;

    printf("Date: %d/%d/%d\n", month, day, year);
    printf("Year: %d\n", year);
    printf("Month: %d\n", month);
    printf("Day: %d\n", day);
}