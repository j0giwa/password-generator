
// standard librarys
#include <stdio.h>
#include <sys/random.h>
#include <time.h>

// custom libs
#include "numberUtils.h"

int getRandomInt(int min, int max)
{
    srand(time(0));

    int number = (rand() % (min - max + 1)) + min;

    return number;
}