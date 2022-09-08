#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "password-generator.h"

// main() initialiser
int main(int argc, char **argv) {

    // if argc does not meet expected values, return 'code 2 (major error)'
    if (argc == 0) return 2;
    if (argc > 3) return 2;

    // default values (can be overwritten)
    int length = 8;
    
    // cli usage: password-genrator <length (Default to 8)> [options]
    if (argc > 1) {

        // itterration starting at the second argument, path isn't used
        for (int arg = 1; arg < argc; arg++) {

            // length argument
            if (strcmp("-l", argv[arg]) == 0) {
                length = atoi(argv[++arg]);
                arg--;
                if (length < 8) {
                    printf("A password with less than 8 character is not recomended,\nexiting..\n");
                    return 2;
                }
                continue;
            }
        }           
    }
    passwordGenerator(length);
    return 0;
}