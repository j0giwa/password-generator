#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "randomUtils.h"

char* mergestring(lowercase, uppercase, symbols)
char* lowercase;
char* uppercase;
char* symbols;
{
	int charCount = strlen(lowercase) + strlen(uppercase) + strlen(symbols);
	char *str = malloc(sizeof(char) * charCount);
	strcat(str, uppercase);
	strcat(str, lowercase);
	strcat(str, symbols);
	return str;
}

char* scrambler(input, length)
char* input;
int length;
{
	char* output = input;
	char oldChar;
	char newChar;
	int index = 0;
	for (int i = 0; i <= (length-1); i++) {
		index = getRandomInt(0, length);
		oldChar = output[i];
		newChar = output[index];
		output[i] = newChar;
		output[index] = oldChar;
	}
	return output;
}

void passwordGenerator(length)
int length;
{
	int* amount;
	int lowerCount;
	int upperCount;
	int symCount;
	char* lowerChars;
	char* upperChars;
	char* symChars;
	char* password;
	char* scrambleChars;
	srand(time(0));
	amount = intSplitter(3, length);
	lowerCount = amount[0];
	upperCount = amount[1];
	symCount   = amount[2];
	lowerChars = malloc(sizeof(int) * lowerCount);
	upperChars = malloc(sizeof(int) * upperCount);
	symChars   = malloc(sizeof(int) * symCount);
	strcpy(lowerChars, getRandomChars(lowerCount, false));
	strcpy(upperChars, getRandomChars(upperCount, true));
	strcpy(symChars,   getRandomSymbols(symCount));
	password = mergestring(lowerChars, upperChars, symChars);
	scrambleChars = scrambler(password, length);
	free(lowerChars);
	free(upperChars);
	free(symChars);
	printf("Password:    %s\n", scrambleChars);
	return;
}
