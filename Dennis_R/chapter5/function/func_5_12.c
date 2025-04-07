/* Extend entab and detab to accept the shorthand 

entab -m +n 

to mean tab stops every n columns, starting at column m. Choose convenient (for the user) default behavior. 

Author  : Aditya Nathwani
Created : 20 March, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int m = 0; // Starting column
int n = 4; // Tab stop every n columns

int tabstop(int col) {
	if (col < m)
		return 1; // Before starting column, treat every position as a tab stop = 1
	return n - ((col - m) % n);
}

void Detab() {
	int c, col = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar(c);
			col = 0;
		} else if (c == '\t') {
			int spaces = tabstop(col);
			for (int i = 0; i < spaces; ++i) {
				putchar(' ');
				col++;
			}
		} else {
			putchar(c);
			col++;
		}
	}
}

void Entab() {
	int c, col = 0, spaceCount = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			spaceCount++;
			if (spaceCount == tabstop(col - spaceCount + 1)) {
				putchar('\t');
				col += spaceCount;
				spaceCount = 0;
			}
		} else {
			for (int i = 0; i < spaceCount; ++i) {
				putchar(' ');
				col++;
			}
			spaceCount = 0;
			putchar(c);
			if (c == '\n') {
				col = 0;
			} else {
				col++;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <detab|entab> [-m start_col] [+n tab_every_n_cols]\n", argv[0]);
		return 1;
	}

	for (int i = 2; i < argc; i++) {
		if (argv[i][0] == '-' && isdigit(argv[i][1])) {
			m = atoi(&argv[i][1]);
		} else if (argv[i][0] == '+' && isdigit(argv[i][1])) {
			n = atoi(&argv[i][1]);
		} else {
			fprintf(stderr, "Invalid option: %s\n", argv[i]);
			return 1;
		}
	}

	if (strcmp(argv[1], "detab") == 0) {
		Detab();
	} else if (strcmp(argv[1], "entab") == 0) {
		Entab();
	} else {
		fprintf(stderr, "Invalid command. Use 'detab' or 'entab'.\n");
		return 1;
	}

	return 0;
}

