#ifndef PASSWORGENERRATOR_H
#define PASSWORGENERRATOR_H

// Standard Libs
#include <stdbool.h>

char *mergestring(char *uppercase, char *lowercase, char *symbols, int length);

char *scrambler(char *input, int length);

void passwordGenerator(int length, bool lowercase, bool uppercase, bool symbols);

#endif