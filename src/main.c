// Standard Libs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Custom Libs
#include "password-generator.h"

// main() initialiser
int main(int argc, char **argv) {

    // if argc does not meet expected values, return 'code 2 (major error)'
    if (argc == 0) return 2;
    if (argc > 6) return 2;

    // default values (can be overwritten)
    int length = 8;
    bool uppercase = true;
    bool lowercase = true;
    bool symbols   = true;

    // cli usage: password-genrator <length (Default to 8)> [options]
    if (argc > 1) {

        // prepare parameters for custom values
        uppercase = false;
        lowercase = false;
        symbols = false;

        // itterration starting at the second argument, path isn't used
        for (int arg = 1; arg < argc; arg++) {

            // lenght argument
            if (strcmp("-l", argv[arg]) == 0) {
                length = atoi(argv[++arg]);
                arg--;
                continue;
            }
            // enable uppercase
            if (strcmp("-U", argv[arg]) == 0) {
                uppercase = true;
                continue;
            }
            // enable lowercase
            if (strcmp("-L", argv[arg]) == 0) {
                lowercase = true;
                continue;
            }
            //enabe symbols
            if (strcmp("-S", argv[arg]) == 0) {
                symbols = true;
                continue;
            }
        }           
    }
    passwordGenerator(length, lowercase, uppercase, symbols);
    return 0;
}