#include <stdbool.h>

#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

/**
 * @brief Generate a random Integer
 *
 * @param min bottom limit of integer
 * @param max uppper limit of integer
 *
 * @return int
 */
int getRandomInt(int min, int max);

/**
 * @brief Generate a set of random symbols
 *
 * @param length the amount off symbols
 *
 * @return *char
 */
char* getRandomSymbols(int length);

/**
 * @brief Generate a set of random characters
 *
 * @param length the amount off characters
 * @param uppercase set if the characetrs should be in uppercase or not
 *
 * @return *char
 */
char* getRandomChars(int length, bool uppercase);

int* intSplitter(int integer, int parts);

#endif
