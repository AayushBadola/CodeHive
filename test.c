/**
 * test.c
 *
 * Test program for the CodeHive library
 *
 * Version: Alpha 1.0.0
 * Author: Aayush Badola
 */

#include <stdio.h>
#include <stdlib.h>
#include "CodeHive.h"

int main(int argc, char *argv[])
{
    // Initialize global args
    set_args(argc, argv);

    // Print header
    println("CodeHive Library Test Program");
    println("Version: Alpha 1.0.0");
    println("-----------------------------");
    
    // Test command-line arguments
    println("Command-line Arguments: %d", argument_count());
    for (int i = 0; i < argument_count(); i++) {
        println("Argument %d: %s", i, arguments()[i]);
    }
    println("-----------------------------");

    // Test get_string
    println("Testing get_string():");
    char *name = get_string("Enter your name: ");
    if (name != NULL) {
        println("Hello, %s!", name);
        free(name);  // Don't forget to free the memory
    } else {
        eprintln("Error getting input");
    }
    println("-----------------------------");

    // Test get_char
    println("Testing get_char():");
    char c = get_char("Enter a character: ");
    if (c != CHAR_MAX) {
        println("You entered: '%c'", c);
    } else {
        eprintln("Error getting input");
    }
    println("-----------------------------");

    // Test get_int
    println("Testing get_int():");
    int num = get_int("Enter an integer: ");
    if (num != INT_MAX) {
        println("You entered: %d", num);
    } else {
        eprintln("Error getting input");
    }
    println("-----------------------------");

    // Test get_float
    println("Testing get_float():");
    float f = get_float("Enter a float: ");
    if (f != FLT_MAX) {
        println("You entered: %.2f", f);
    } else {
        eprintln("Error getting input");
    }
    println("-----------------------------");
    
    // Test println and eprintln
    println("Testing println() and eprintln():");
    println("This is a normal message");
    eprintln("This is an error message");
    println("-----------------------------");

    println("All tests completed!");
    return 0;
}
