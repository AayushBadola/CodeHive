/**
 * CodeHive.h
 *
 * A simplified header file inspired by CS50's library
 * Provides easy-to-use functions for input/output and other common operations
 *
 * Version: Alpha 1.0.0
 * Author: Aayush Badola
 */

#ifndef CODEHIVE_H
#define CODEHIVE_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Returns the number of arguments passed to a program from the command line.
 */
int argument_count(void);

/**
 * Returns an array of strings representing command line arguments.
 */
char **arguments(void);

/**
 * Reads a line of text from standard input and returns it as a string,
 * sans trailing line ending. Supports CR (\r), LF (\n), and CRLF (\r\n).
 */
char *get_string(const char *prompt);

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * Leading and trailing whitespace is ignored. If line can't be read, returns CHAR_MAX.
 */
char get_char(const char *prompt);

/**
 * Reads a line of text from standard input and returns the equivalent
 * double; if text does not represent a double, user is prompted to retry.
 * Leading and trailing whitespace is ignored. If line can't be read, returns DBL_MAX.
 */
double get_double(const char *prompt);

/**
 * Reads a line of text from standard input and returns the equivalent
 * float; if text does not represent a float, user is prompted to retry.
 * Leading and trailing whitespace is ignored. If line can't be read, returns FLT_MAX.
 */
float get_float(const char *prompt);

/**
 * Reads a line of text from standard input and returns the equivalent
 * int; if text does not represent an int, user is prompted to retry.
 * Leading and trailing whitespace is ignored. If line can't be read, returns INT_MAX.
 */
int get_int(const char *prompt);

/**
 * Reads a line of text from standard input and returns the equivalent
 * long; if text does not represent a long, user is prompted to retry.
 * Leading and trailing whitespace is ignored. If line can't be read, returns LONG_MAX.
 */
long get_long(const char *prompt);

/**
 * Reads a line of text from standard input and returns the equivalent
 * long long; if text does not represent a long long, user is prompted to retry.
 * Leading and trailing whitespace is ignored. If line can't be read, returns LLONG_MAX.
 */
long long get_long_long(const char *prompt);

/**
 * Print formatted output with a new line at the end.
 */
void println(const char *format, ...);

/**
 * Print a string to stderr.
 */
void eprint(const char *format, ...);

/**
 * Print a string to stderr with a new line at the end.
 */
void eprintln(const char *format, ...);

#endif // CODEHIVE_H
