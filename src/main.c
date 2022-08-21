// Standard Libs
#include <stdio.h>

// Custom Libs
#include "numberUtils.h"

// Mainmethod as an initialiser
int main(int argc, char **argv)
{
    // If argc is for some reason eaqual to 0, return 'exit code 2 (major error)'
    if (argc == 0)
    {
        return 2;
    }

    // If argc exeeds expected params, return 'exit code 1 (minor error)'
    if (argc >= 2)
    {
        return 1;
    }

    int i = getRandomInt(1, 500);
    printf("Test: %i\n", i);
    printf("argc: %i\n", argc);

    return 0;
}