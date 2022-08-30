// Standard Libs
#include <stdio.h>
#include <stdlib.h>

// Custom Libs
#include "password-generator.h"

// main() initialiser
int main(int argc, char **argv) {
    // If argc is for some reason eaqual to 0,
    // return 'exit code 2 (major error)'.
    if (argc == 0) return 2;

    // If argc exeeds expected params,
    // return 'exit code 1 (minor error)'.
    if (argc >= 2) return 1;

    passwordGenerator();

    return 0;
}