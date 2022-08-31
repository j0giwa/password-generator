// Standard Libs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Custom Libs
#include "numberUtils.h"

// Colors for output
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

char *getRandomSymbols(int length) {
    // Guardstatement to prevent invalid parameters
    if (length <= 0) return "";

    int asciival = 0;
    char *asciichar = malloc(sizeof(int) * 1);
    char *returnValue = malloc(sizeof(int) * length);

    int firstSymbolChar = 33; // Corresponds to '!'
    int lastSymbolChar = 47;  // Corresponds to '/'

    for (int i = 0; i < length; i++)
    {
        asciival = getRandomInt(firstSymbolChar, lastSymbolChar);
        // Converting ascii code to character
        snprintf(asciichar, 2, "%c", asciival);
        strncpy(&returnValue[i], asciichar, 2);
    }

    return returnValue;
}

char *getRandomChars(int length, bool uppercase) {
    // Guardstatement to prevent invalid parameters
    if (length <= 0) return "";

    int asciival = 0;
    char *asciichar = malloc(sizeof(int) * 1);
    char *returnValue = malloc(sizeof(int) * length);

    int firstLowerChar = 97; // Corresponds to 'a'
    int lastLowerChar = 122; // Corresponds to 'z'
    int firstUpperChar = 65; // Corresponds to 'A'
    int lastUpperChar = 90;  // Corresponds to 'Z'

    if (uppercase)
    {
        for (int i = 0; i < length; i++)
        {
            asciival = getRandomInt(firstUpperChar, lastUpperChar);
            // Converting ascii code to character
            snprintf(asciichar, 2, "%c", asciival);
            strncpy(&returnValue[i], asciichar, 2);
        }
        return returnValue;
    }

    for (int i = 0; i < length; i++)
    {
        asciival = getRandomInt(firstLowerChar, lastLowerChar);
        // Converting ascii code to character
        snprintf(asciichar, 2, "%c", asciival);
        strncpy(&returnValue[i], asciichar, 2);
    }
    return returnValue;
}

char *mergestring(char *uppercase, char *lowercase, char *symbols, int length) {
    // TODO: change 24 with actual stringlength
    char *str = malloc(sizeof(char) * length);

    if (uppercase != "") strcat(str, uppercase);

    if (lowercase != "") strcat(str, lowercase);

    if (symbols != "") strcat(str, symbols);

    return str;
}

char *scrambler(char *input, int length)
{
    char oldChar;
    char newChar;
    int index = 0;

    for (int i = 0; i >= length; i++)
    {
        index = getRandomInt(0, length);

        oldChar = input[i];
        newChar = input[index];

        input[i] = newChar;
        input[index] = oldChar;
    }

    return input;
}

int *intSplitter(int integer, int parts) {

    int *returnVal = NULL;
    int calcVal = 0;

    for (int i = 0 ; i < parts ; i++) {

        calcVal = getRandomInt(1, integer);
        returnVal[i] = calcVal;
        printf("returnVal[%d]: %d", i, calcVal);
        integer = integer - calcVal;
    }

    return returnVal;
}

void passwordGenerator(int length, bool lowercase, bool uppercase, bool symbols) {

    srand(time(0));

    //int *amount = intSplitter(length, 3);

    int testDivider = length / 3; // just for debug
    int lowercaseCount = (lowercase) ? testDivider : 0;
    int uppercaseCount = (uppercase) ? testDivider : 0;
    int symbolsCount = (symbols) ? testDivider : 0;
    int totalCount = lowercaseCount + uppercaseCount + symbolsCount; //just for debug

    //printf("Lowercase-characters: %d\n", lowercaseCount);
    //printf("Uppercase-characters: %d\n", uppercaseCount);
    //printf("Symbol-characters: %d\n", symbolsCount);

    // char *lowercaseChars = getRandomChars(lowercaseCount, false);
    // char *uppercaseChars = getRandomChars(uppercaseCount, true);
    // char *symbolsChars = getRandomSymbols(symbolsCount);

    char *lowercaseChars = getRandomChars(lowercaseCount, false);
    char *uppercaseChars = getRandomChars(uppercaseCount, true);
    char *symbolsChars = getRandomSymbols(symbolsCount);
    char *mergedChars = mergestring(lowercaseChars, uppercaseChars, symbolsChars, totalCount);
    char *scrambleChars = scrambler(mergedChars, totalCount);

    // printf(ANSI_YELLOW "LowerCase ASCII-test: " ANSI_BLUE "%s\n" ANSI_RESET, lowercaseChars);
    // printf(ANSI_YELLOW "Uppercase ASCII-test: " ANSI_BLUE "%s\n" ANSI_RESET, uppercaseChars);
    // printf(ANSI_YELLOW "Symbol ASCII-test:    " ANSI_BLUE "%s\n" ANSI_RESET, symbolsChars);
    
    printf(ANSI_YELLOW "Password:        " ANSI_BLUE "%s\n" ANSI_RESET, scrambleChars);

    return;
}