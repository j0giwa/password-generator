// Standard Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom Libs
#include "numberUtils.h"

char *getRandomChars(int length)
{
    // Guardstatement to prevent invalid parameters
    if (length <= 0) return NULL;

    int asciival = 0;
    char *asciichar = malloc(sizeof(int) * 1);
    char *returnValue = malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++)
    {
        // 65 = A, 90 = Z
        asciival = getRandomInt(65, 90, asciival);
        snprintf(asciichar, 2, "%c", asciival); // Converting ascii code to character
        strncpy(&returnValue[i], asciichar, 2);
    }
    return returnValue;
}

// Mainmethod as an initialiser
int main(int argc, char **argv)
{
    // If argc is for some reason eaqual to 0, return 'exit code 2 (major error)'
    if (argc == 0) return 2;

    // If argc exeeds expected params, return 'exit code 1 (minor error)'
    if (argc >= 2) return 1;

    int i = getRandomInt(1, 500, 0);
    printf("Random Number Generator Test: %i\n", i);
    printf("argc: %i\n", argc);

    printf("ascii test: %s\n", getRandomChars(5));

    return 0;
}