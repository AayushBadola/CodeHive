/**
 * CodeHive.c
 *
 * Implementation of the CodeHive library functions
 *
 * Version: Alpha 1.0.0
 * Author: Aayush Badola
 */

#include "CodeHive.h"

#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
static int argc_global = 0;
static char **argv_global = NULL;

// Define a buffer size for reading input
#define BUFFER_SIZE 2048

/**
 * Set command-line arguments for later use
 */
void set_args(int argc, char **argv) {
    argc_global = argc;
    argv_global = argv;
}

/**
 * Returns the number of arguments passed to a program from the command line.
 */
int argument_count(void) {
    return argc_global;
}

/**
 * Returns an array of strings representing command line arguments.
 */
char **arguments(void) {
    return argv_global;
}

/**
 * Read a line from stdin.
 */
static char *read_line(const char *prompt) {
    // Print prompt if provided
    if (prompt != NULL) {
        printf("%s", prompt);
        fflush(stdout);
    }

    // Allocate buffer for line
    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        return NULL;
    }

    // Try to read a line from stdin
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        free(buffer);
        return NULL;
    }

    // Remove trailing newline characters (supports CR, LF, and CRLF)
    char *p = buffer + strlen(buffer);
    while (p > buffer && (*(p - 1) == '\n' || *(p - 1) == '\r')) {
        *--p = '\0';
    }

    return buffer;
}

/**
 * Reads a line of text from standard input and returns it as a string,
 * sans trailing line ending. Supports CR (\r), LF (\n), and CRLF (\r\n).
 */
char *get_string(const char *prompt) {
    return read_line(prompt);
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 */
char get_char(const char *prompt) {
    while (true) {
        // Get string
        char *line = get_string(prompt);
        if (line == NULL) {
            return CHAR_MAX;
        }

        // Return char if exactly one character
        char c = '\0', d = '\0';
        if (sscanf(line, " %c%c", &c, &d) == 1) {
            free(line);
            return c;
        }

        free(line);
        printf("Invalid input. Please enter a single character.\n");
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * double; if text does not represent a double, user is prompted to retry.
 */
double get_double(const char *prompt) {
    while (true) {
        // Get string
        char *line = get_string(prompt);
        if (line == NULL) {
            return DBL_MAX;
        }

        // Return double if valid
        char *end;
        errno = 0;
        double d = strtod(line, &end);
        if (line != end && *end == '\0' && !errno) {
            free(line);
            return d;
        }

        free(line);
        printf("Invalid input. Please enter a numeric value.\n");
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * float; if text does not represent a float, user is prompted to retry.
 */
float get_float(const char *prompt) {
    while (true) {
        // Get string
        char *line = get_string(prompt);
        if (line == NULL) {
            return FLT_MAX;
        }

        // Return float if valid
        char *end;
        errno = 0;
        float f = strtof(line, &end);
        if (line != end && *end == '\0' && !errno) {
            free(line);
            return f;
        }

        free(line);
        printf("Invalid input. Please enter a numeric value.\n");
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * int; if text does not represent an int, user is prompted to retry.
 */
int get_int(const char *prompt) {
    while (true) {
        // Get string
        char *line = get_string(prompt);
        if (line == NULL) {
            return INT_MAX;
        }

        // Return int if valid
        char *end;
        errno = 0;
        long l = strtol(line, &end, 10);
        if (line != end && *end == '\0' && !errno && l >= INT_MIN && l <= INT_MAX) {
            free(line);
            return (int) l;
        }

        free(line);
        printf("Invalid input. Please enter an integer.\n");
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * long; if text does not represent a long, user is prompted to retry.
 */
long get_long(const char *prompt) {
    while (true) {
        // Get string
        char *line = get_string(prompt);
        if (line == NULL) {
            return LONG_MAX;
        }

        // Return long if valid
        char *end;
        errno = 0;
        long l = strtol(line, &end, 10);
        if (line != end && *end == '\0' && !errno) {
            free(line);
            return l;
        }

        free(line);
        printf("Invalid input. Please enter an integer.\n");
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * long long; if text does not represent a long long, user is prompted to retry.
 */
long long get_long_long(const char *prompt) {
    while (true) {
        // Get string
        char *line = get_string(prompt);
        if (line == NULL) {
            return LLONG_MAX;
        }

        // Return long long if valid
        char *end;
        errno = 0;
        long long ll = strtoll(line, &end, 10);
        if (line != end && *end == '\0' && !errno) {
            free(line);
            return ll;
        }

        free(line);
        printf("Invalid input. Please enter an integer.\n");
    }
}

/**
 * Print formatted output with a new line at the end.
 */
void println(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

/**
 * Print a string to stderr.
 */
void eprint(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

/**
 * Print a string to stderr with a new line at the end.
 */
void eprintln(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, "\n");
}
