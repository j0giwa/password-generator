#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/**
 * Produces a random 16-bit integer
 */
int get_next_int(min, max) 
        int min;
        int max;
{
	int num = (rand() % (min - max + 1)) + min;
	return num;
}

/**
 * Prduced a char* of random ascii characters
 */
char* get_ascii(length)
        int length;
{
    	int ascii_val, first_char, last_char;
    	char *ascii_char, *ascii_string;

	if (length <= 0)
		return "";

    	ascii_char = (char*) malloc(sizeof(int) * 1);
    	ascii_string = (char*) malloc(sizeof(int) * length);
    	first_char = 32;
    	last_char = 127;

        for (int i = 0; i < length; i++) {
		ascii_val = get_next_int(first_char, last_char);
		snprintf(ascii_char, 2, "%c", ascii_val);
		strncpy(&ascii_string[i], ascii_char, 2);
	}

	return ascii_string;
}

/**
 * Prints a semi-secure password to stdout
 */
void passwd_gen(length)
        int length;
{
	char *passwd;
	srand(time(0));
	passwd = get_ascii(length);
	printf("Password: %s\n", passwd);
	return;
}

int main(argc, argv)
        int argc;
        char** argv;
{
	if (argc == 0)
		return 2;
	if (argc > 3)
		return 2;
	if (argc == 1) {
		passwd_gen(8);
		return EXIT_SUCCESS;
	}

	int length;

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

	passwd_gen(length);
	return EXIT_SUCCESS;
}

