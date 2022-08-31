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

    // If argc does not meet expected values,
    // return 'exit code 2 (major error)'.
    if (argc == 0) return 2;
    if (argc > 6) return 2;

    // Defaul values,a ben ovewritten with arguments
    int length = 9;
    bool uppercase = true;
    bool lowercase = true;
    bool symbols   = true;

    /*
        Argument parser
        cli usage: password-genrator <length (Default to 8)> [options]
    */
    if (argc > 1) {

        // reset prameters,beaccuse cusom values are supplied
        uppercase = false;
        lowercase = false;
        symbols = false;

        // Itterration starting at second argument because path is not needed
        for (int arg = 1; arg < argc; arg++) {

            // Lengght argument
            if (strcmp("-l", argv[arg]) == 0) {
                length = atoi(argv[++arg]);
                arg--;
                continue;
            }

            if (strcmp("-U", argv[arg]) == 0) {
                uppercase = true;
                continue;
            }

            if (strcmp("-L", argv[arg]) == 0) {
                lowercase = true;
                continue;
            }

            if (strcmp("-S", argv[arg]) == 0) {
                symbols = true;
                continue;
            }
        }           
    }

    printf("Chars:%d\n", length);

    passwordGenerator(length, lowercase, uppercase, symbols);
    return 0;
}