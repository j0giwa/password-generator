// Standard Libs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Custom Libs
#include "randomUtils.h"

// Colors for output
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

char *mergestring(char *uppercase, char *lowercase, char *symbols, int length) {
    // TODO: change 24 with actual stringlength
    char *str = malloc(sizeof(char) * length);

    if (strcmp(uppercase, "") != 0) strcat(str, uppercase);

    if (strcmp(lowercase, "") != 0) strcat(str, lowercase);

    if (strcmp(symbols, "") != 0) strcat(str, symbols);

    return str;
}

char *scrambler(char *input, int length) {
    char oldChar;
    char newChar;
    int index = 0;

    for (int i = 0; i <= (length-1); i++)
    {
        index = getRandomInt(0, length);

        oldChar = input[i];
        newChar = input[index];

        input[i] = newChar;
        input[index] = oldChar;
    }

    return input;
}

void passwordGenerator(int length, bool lowercase, bool uppercase, bool symbols) {

    srand(time(0));

    int *amount = intSplitter(3, length);
    int lowercaseCount = (lowercase) ? amount[0] : 0;
    int uppercaseCount = (uppercase) ? amount[1] : 0;
    int symbolsCount   = (symbols)   ? amount[2] : 0;

    /*
    int testDivider = length / 3; // just for debug
    int lowercaseCount = (lowercase) ? testDivider : 0;
    int uppercaseCount = (uppercase) ? testDivider : 0;
    int symbolsCount = (symbols) ? testDivider : 0;
    */

    char *lowercaseChars = malloc(sizeof(int) * lowercaseCount);
    char *uppercaseChars = malloc(sizeof(int) * uppercaseCount);
    char *symbolsChars = malloc(sizeof(int) * symbolsCount);

    strcpy(lowercaseChars,getRandomChars(lowercaseCount, false));
    strcpy(uppercaseChars, getRandomChars(uppercaseCount, true));
    strcpy(symbolsChars, getRandomSymbols(symbolsCount));

    char *mergedChars = mergestring(lowercaseChars, uppercaseChars, symbolsChars, length);
    char *scrambleChars = scrambler(mergedChars, length);
    
    printf(ANSI_YELLOW "Password:        " ANSI_BLUE "%s\n" ANSI_RESET, scrambleChars);

    return;
}