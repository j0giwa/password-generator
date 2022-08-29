#ifndef NUMBERUTILS_H
#define NUMBERUTILS_H

/**
 * @brief Generate a random Integer
 *
 * @param min bottom limit of integer
 * @param max uppper limit of integer
 * @param seed seed for the calulation (Will use timestamp if equal to 0)
 *
 * @return int
 */
int getRandomInt(int min, int max, int seed);

#endif