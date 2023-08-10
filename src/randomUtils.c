#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>

int getRandomInt(min, max) 
int min;
int max;
{
	int number = (rand() % (min - max + 1)) + min;
	return number;
}

char* getRandomSymbols(length)
int length;
{
	int i, asciival, firstCharCode, lastCharCode;
	char *asciichar, *returnValue;
	if (length <= 0)
		return "";
	asciival = 0;
	asciichar = (char *) malloc(sizeof(int) * 1);
	returnValue = (char *) malloc(sizeof(int) * length);
	firstCharCode = 33; /* Corresponds to '!' */
	lastCharCode = 47;  /* Corresponds to '/' */
	for (i = 0; i < length; i++) {
		asciival = getRandomInt(firstCharCode, lastCharCode);
		snprintf(asciichar, 2, "%c", asciival);
		strncpy(&returnValue[i], asciichar, 2);
	}
	return returnValue;
}

char* getRandomChars(length, uppercase)
int length;
int uppercase;
{
    	int i, asciival, firstCharCode, lastCharCode;
    	char *asciichar, *returnValue;
	if (length <= 0)
		return "";
    	asciichar = (char*) malloc(sizeof(int) * 1);
    	returnValue = (char*) malloc(sizeof(int) * length);
    	firstCharCode = 97; /* corresponds to 'a' */
    	lastCharCode = 122; /* corresponds to 'z' */
	if (uppercase) {
		firstCharCode -= 32; /* now corresponds to 'A' */
    		lastCharCode -= 32;  /* now corresponds to 'Z' */
	}
	for (i = 0; i < length; i++) {
		asciival = getRandomInt(firstCharCode, lastCharCode);
		snprintf(asciichar, 2, "%c", asciival);
		strncpy(&returnValue[i], asciichar, 2);
	}
	return returnValue;
}


int* intSplitter(count, target)
int count;
int target;
{
	int i, *result;
	double minValue, maxValue, currentsum, low, high, calc;
    	if (target == 0 || count == 0)
        	return 0;
	minValue = 1;
	maxValue = 9;
	currentsum = 0;
	low = 0;
	high = 0;
	calc = 0;
	result = (int *) malloc(sizeof(int) * count);
	for (i = 0; i < count; i++) {
		calc = (target - currentsum) - (maxValue * (count - 1 - i));
		low = calc < minValue ? minValue : calc;
		calc = (target - currentsum) - (minValue * (count - 1 - i));
		high = calc > maxValue ? maxValue : calc;
		result[i] = getRandomInt((int) low, (int) high);
		currentsum += result[i];
	}
	return result;
}
