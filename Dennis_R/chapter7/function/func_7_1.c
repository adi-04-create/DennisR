#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int c;

	// Default: convert to lower case
	int to_lower = 1;

	// Check the program name to determine behavior
	if (argc > 0 && strstr(argv[0], "upper") != NULL) {
		to_lower = 0;  // Convert to upper case
	}

	while ((c = getchar()) != EOF) {
		putchar(to_lower ? tolower(c) : toupper(c));
	}

	return 0;
}

