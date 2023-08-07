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
	int i;
	int asciival;
	char* asciichar;
	char* returnValue;
	int firstSymbolChar;
	int lastSymbolChar;
	if (length <= 0)
		return "";
	asciival = 0;
	asciichar = (char *) malloc(sizeof(int) * 1);
	returnValue = (char *) malloc(sizeof(int) * length);
	firstSymbolChar = 33; /* Corresponds to '!' */
	lastSymbolChar = 47;  /* Corresponds to '/' */
	for (i = 0; i < length; i++) {
		asciival = getRandomInt(firstSymbolChar, lastSymbolChar);
		snprintf(asciichar, 2, "%c", asciival);
		strncpy(&returnValue[i], asciichar, 2);
	}
	return returnValue;
}

char* getRandomChars(length, uppercase)
int length;
int uppercase;
{
    	int i;
	int asciival;
    	char* asciichar;
    	char* returnValue;
    	int firstChar;
    	int lastChar;

	if (length <= 0)
		return "";

    	asciichar = (char*) malloc(sizeof(int) * 1);
    	returnValue = (char*) malloc(sizeof(int) * length);

    	firstChar = 97; /* corresponds to 'a' */
    	lastChar = 122; /* corresponds to 'z' */
    	
	if (uppercase) {
		firstChar -= 32; /* now corresponds to 'A' */
    		lastChar -= 32;  /* now corresponds to 'Z' */
	}

	for (i = 0; i < length; i++) {
		asciival = getRandomInt(firstChar, lastChar);
		snprintf(asciichar, 2, "%c", asciival);
		strncpy(&returnValue[i], asciichar, 2);
	}
	return returnValue;
}


int* intSplitter(count, target)
int count;
int target;
{
	int i;
	double minValue;
	double maxValue;
	double currentsum;
	double low;
	double high;
	double calc;
	int* result;
    
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
