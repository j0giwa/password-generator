// Standard Libs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Custom Libs
#include "numberUtils.h"

// Colors for output
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

/**
 * @brief Generate a set of random symbols
 *
 * @param length the amount off symbols
 *
 * @return *char
 */
char *getRandomSymbols(int length) {
    // Guardstatement to prevent invalid parameters
    if (length <= 0) return NULL;

    int asciival = 0;
    char *asciichar = malloc(sizeof(int) * 1);
    char *returnValue = malloc(sizeof(int) * length);

    int firstSymbolChar = 33;    // Corresponds to '!'
    int lastSymbolChar  = 47;   // Corresponds to '/'

    for (int i = 0; i < length; i++) {
        asciival = getRandomInt(firstSymbolChar, lastSymbolChar);
        // Converting ascii code to character
        snprintf(asciichar, 2, "%c", asciival);
        strncpy(&returnValue[i], asciichar, 2);
    }

    return returnValue;
}

/**
 * @brief Generate a set of random characters
 *
 * @param length the amount off characters
 * @param uppercase set if the characetrs should be in uppercase or not
 *
 * @return *char
 */
char *getRandomChars(int length, bool uppercase) {
    // Guardstatement to prevent invalid parameters
    if (length <= 0) return NULL;

    int asciival = 0;
    char *asciichar = malloc(sizeof(int) * 1);
    char *returnValue = malloc(sizeof(int) * length);

    int firstLowerChar = 97;    // Corresponds to 'a'
    int lastLowerChar  = 122;   // Corresponds to 'z'
    int firstUpperChar = 65;    // Corresponds to 'A'
    int lastUpperChar  = 90;    // Corresponds to 'Z'

    if (uppercase) {
        for (int i = 0; i < length; i++) {
            asciival = getRandomInt(firstUpperChar, lastUpperChar);
            // Converting ascii code to character
            snprintf(asciichar, 2, "%c", asciival);
            strncpy(&returnValue[i], asciichar, 2);
        }
        return returnValue;
    }

    for (int i = 0; i < length; i++) {
        asciival = getRandomInt(firstLowerChar, lastLowerChar);
        // Converting ascii code to character
        snprintf(asciichar, 2, "%c", asciival);
        strncpy(&returnValue[i], asciichar, 2);
    }
    return returnValue;
}

/**
 * @brief Regorganise a string ins an random order
 *
 * @param input input
 *
 * @return *char
 */
void scrambler(char *input) {



}

char *mergestring(char *uppercase, char *lowercase, char *symbols)
{
    // TODO: change 24 with actual stringlength
    char *str = malloc(sizeof(char) * 24); 
    strcat(str, uppercase);
    strcat(str, lowercase);
    strcat(str, symbols);
    return str;
}

// main() initialiser
int main(int argc, char **argv) {
    // If argc is for some reason eaqual to 0,
    // return 'exit code 2 (major error)'.
    if (argc == 0) return 2;

    // If argc exeeds expected params,
    // return 'exit code 1 (minor error)'.
    if (argc >= 2) return 1;

    srand(time(0));

    int i = getRandomInt(4, 8);
    char *uppercase = getRandomChars(i, true);
    char *lowercase = getRandomChars(i, false);
    char *symbols = getRandomSymbols(i);

    printf(ANSI_YELLOW "Random Number Test:   " ANSI_BLUE "%i\n" ANSI_RESET, i);
    printf(ANSI_YELLOW "Uppercase ASCII-test: " ANSI_BLUE "%s\n" ANSI_RESET, uppercase);
    printf(ANSI_YELLOW "LowerCase ASCII-test: " ANSI_BLUE "%s\n" ANSI_RESET, lowercase);
    printf(ANSI_YELLOW "Symbol ASCII-test:    " ANSI_BLUE "%s\n" ANSI_RESET, symbols);
    printf(ANSI_YELLOW "Join-test:            " ANSI_BLUE "%s\n" ANSI_RESET, mergestring(uppercase, lowercase, symbols));
    // printf(ANSI_YELLOW "Scramble-test:        " ANSI_BLUE "%s\n" ANSI_RESET, scrambler(i));

    return 0;
}