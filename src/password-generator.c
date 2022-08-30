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

char *getRandomSymbols(int length)
{
    // Guardstatement to prevent invalid parameters
    if (length <= 0)
        return NULL;

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

char *getRandomChars(int length, bool uppercase)
{
    // Guardstatement to prevent invalid parameters
    if (length <= 0)
        return NULL;

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

char *mergestring(char *uppercase, char *lowercase, char *symbols)
{
    // TODO: change 24 with actual stringlength
    char *str = malloc(sizeof(char) * 24);
    strcat(str, uppercase);
    strcat(str, lowercase);
    strcat(str, symbols);
    return str;
}

char *scrambler(char *input)
{
    char oldChar;
    char newChar;
    int index = 0;

    for (int i = 0; i < 24; i++)
    {
        index = getRandomInt(0, 24);

        oldChar = input[i];
        newChar = input[index];

        input[i] = newChar;
        input[index] = oldChar;
    }

    return input;
}

void passwordGenerator()
{

    srand(time(0));

    char *uppercase = getRandomChars(8, true);
    char *lowercase = getRandomChars(8, false);
    char *symbols = getRandomSymbols(8);
    char *join = mergestring(uppercase, lowercase, symbols);
    char *scramble = scrambler(join);

    printf(ANSI_YELLOW "Password:        " ANSI_BLUE "%s\n" ANSI_RESET, scramble);

    return;
}