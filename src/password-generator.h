#ifndef PASSWORGENERRATOR_H
#define PASSWORGENERRATOR_H

// Standard Libs
#include <stdbool.h>
// Custom Libs
#include "numberUtils.h"

/**@brief Generate a set of random symbols
 *
 * @param length the amount off symbols
 *
 * @ return *char 
 */
char * getRandomSymbols(int length);

/**
 * @brief Generate a set of random characters
 *
 * @param length the amount off characters
 * @param uppercase set if the characetrs should be in uppercase or not
 *
 * @return *char
 */
char *getRandomChars(int length, bool uppercase);

char *mergestring(char *uppercase, char *lowercase, char *symbols);

void passwordGenerator();

#endif