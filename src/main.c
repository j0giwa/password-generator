#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "password-generator.h"

int main(argc, argv)
int argc;
char** argv;
{
	int length;
	if (argc == 0)
		return 2;
	if (argc > 3)
		return 2;
	if (argc == 1) {
		length = 8;
		passwordGenerator(length);
		return EXIT_SUCCESS;
	}
	for (int arg = 1; arg < argc; arg++) {
		if (strcmp("-v", argv[arg]) == 0) {
			printf("Password-generator\nVersion: 1.0.0.0");
			return EXIT_SUCCESS;
			continue;
		}
		/* print version Information */
		if (strcmp("-v", argv[arg]) == 0) {
			printf("Password-generator\nVersion: 1.0.0.0");
			return EXIT_SUCCESS;
			continue;
		}
		/* Specify string length */
		if (strcmp("-l", argv[arg]) == 0) {
			length = atoi(argv[++arg]);
			arg--;
			if (length < 8) {
				printf("A password with less than 8 character is not recomended,\nexiting..\n");
				return EXIT_FAILURE;
			}
			continue;
		}
	}
	passwordGenerator(length);
	return EXIT_SUCCESS;
}
