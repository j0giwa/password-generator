#ifndef PASSWORGENERRATOR_H
#define PASSWORGENERRATOR_H

// Standard Libs
#include <stdbool.h>

char *mergestring(char *lowercase, char *uppercase, char *symbols);

char *scrambler(char *input, int length);

void passwordGenerator(int length);

#endif