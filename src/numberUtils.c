
// standard librarys
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

// custom libs
#include "numberUtils.h"
int getRandomInt(int min, int max)
{
    int number = (rand() % (min - max + 1)) + min;
    return number;
}
