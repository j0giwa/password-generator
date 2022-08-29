
// standard librarys
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <time.h>

// custom libs
#include "numberUtils.h"

int getRandomInt(int min, int max, int seed)
{
    seed = (seed == 0) ? time(0) : seed; 
    srand(seed);

    int number = (rand() % (min - max + 1)) + min;

    return number;
}