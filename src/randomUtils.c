#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>

int getRandomInt(int min, int max) {
    int number = (rand() % (min - max + 1)) + min;
    return number;
}

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

int *intSplitter(int count, int target) {

    // Guardstatement to prevent invalid parameters
    if (target == 0 || count == 0 ) return 0;

    const int minValue = 1;
    const int maxValue = 9;

    int *result = malloc(sizeof(int) * count);
    int currentsum = 0;
    int low = 0;
    int high = 0;
    int calc = 0;

    for (int i = 0; i < count; i++) {

        calc = (target - currentsum) - (maxValue * (count - 1 - i));
        low = calc < minValue ? minValue : calc;

        calc = (target - currentsum) - (minValue * (count - 1 - i));
        high = calc > maxValue ? maxValue : calc;

        result[i] = getRandomInt(low, high);
        currentsum += result[i];

    }
    return result;
}