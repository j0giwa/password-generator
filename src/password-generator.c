#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "randomUtils.h"

#define ANSI_RED        "\x1b[31m"
#define ANSI_GREEN      "\x1b[32m"
#define ANSI_YELLOW     "\x1b[33m"
#define ANSI_BLUE       "\x1b[34m"
#define ANSI_MAGENTA    "\x1b[35m"
#define ANSI_CYAN       "\x1b[36m"
#define ANSI_RESET      "\x1b[0m"

char *mergestring(char *lowercase, char *uppercase, char *symbols) {

    int charCount = strlen(lowercase) + strlen(uppercase) + strlen(symbols);

    char *str = malloc(sizeof(char) * charCount);

    strcat(str, uppercase);
    strcat(str, lowercase);
    strcat(str, symbols);

    return str;
}

char *scrambler(char *input, int length) {

    char *output = input;

    char oldChar;
    char newChar;
    int index = 0;

    for (int i = 0; i <= (length-1); i++) {

        index = getRandomInt(0, length);

        oldChar = output[i];
        newChar = output[index];

        output[i]     = newChar;
        output[index] = oldChar;
    }
    return output;
}

void passwordGenerator(int length) {

    srand(time(0));

    int *amount = intSplitter(3, length);
    int lowerCount = amount[0];
    int upperCount = amount[1];
    int symCount   = amount[2];

    char *lowerChars = malloc(sizeof(int) * lowerCount);
    char *upperChars = malloc(sizeof(int) * upperCount);
    char *symChars   = malloc(sizeof(int) * symCount);

    strcpy(lowerChars, getRandomChars(lowerCount, false));
    strcpy(upperChars, getRandomChars(upperCount, true));
    strcpy(symChars,   getRandomSymbols(symCount));
    
    char *password = mergestring(lowerChars, upperChars, symChars);
    char *scrambleChars = scrambler(password, length);

    free(lowerChars);
    free(upperChars);
    free(symChars);

    printf(ANSI_YELLOW "Password:      " ANSI_BLUE "%s\n" ANSI_RESET, scrambleChars);

    return;
}