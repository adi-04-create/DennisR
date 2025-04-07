/*
 * Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab
 * stops as arguments. Use the default tab settings if there are no arguments.
 *
 * Author  : Aditya Nathwani
 * Created : 17 March, 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#include "header.h"
#define TABSIZE tab
#define TAB tab
int tab = 4;
void Detab() 
{
	uint32_t iChar, x = 0, r;
	while ((iChar = getchar()) != EOF) 
	{
		if (iChar == '\n') 
		{
			printf("<=this is output\n");
			putchar(iChar);
			x = 0;
		} 
		else if (iChar == '\t') 
		{
			r = TAB - x % TAB;
			while (r-- != 0) 
			{
				putchar(' ');
				x++;
			}
		} 
		else 
		{
			putchar(iChar);
			x++;
		}
	}
}

void Entab() {
	uint32_t c = 0;
	uint32_t spaceCount = 0;

	while ((c = getchar()) != EOF) 
	{
		if (c == ' ') 
		{
			++spaceCount;
			if (spaceCount == TABSIZE) 
			{
				spaceCount = 0;
				putchar('\t'); // Replace spaces with a tab
			}
		} 
		else 
		{
			// Print any remaining spaces before printing the non-space character
			for (uint32_t i = 0; i < spaceCount; ++i) 
			{
				putchar(' ');
			}
			spaceCount = 0;
			putchar(c); // Print the current character
		}
	}
}


//int tab = 4; // Global variable to hold tab size

int main(int argc, char *argv[]) 
{
	if (argc < 3) 
	{
		printf("Usage: %s <detab|entab> <tabsize>\n", argv[0]);
		return 1;
	}

	tab = atoi(argv[2]); // Convert tab size from argument
	if (tab <= 0) 
	{
		printf("Invalid tab size. It must be a positive integer.\n");
		return 1;
	}

	if (strcmp(argv[1], "detab") == 0) 
	{
		Detab();
	} 
	else if (strcmp(argv[1], "entab") == 0) 
	{
		Entab();
	} 
	else 
	{
		fprintf(stderr, "Invalid command. Use 'detab' or 'entab'.\n");
		return 1;
	}

	return 0;
}
