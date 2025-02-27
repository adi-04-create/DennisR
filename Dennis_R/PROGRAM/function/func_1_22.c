#include <stdint.h>
/* Program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. The program handles long lines intelligently and takes care of situations
where there are no blanks or tabs before the specified column.*/
// Author: Aditya Nathwani
// Created: 2 January 2024
// Modified: 2 January 2024

#include <stdio.h>  // Standard input/output library
#include "header.h"
#define MAXCOL 10   // Maximum column width before folding a line
#define TABVAL 8    // Tab width

char line[MAXCOL]; // Array to hold the current line of input

// Function prototypes
uint32_t expandtab(uint32_t pos);  // Expands a tab into spaces
uint32_t printline(uint32_t pos);  // Prints the line
uint32_t getblank(uint32_t pos);   // Finds the last blank character before a specified position
uint32_t newposition(uint32_t pos); // Adjusts the position after folding the line

void fold()
{
    	uint32_t pos, c;
    	pos = 0;  // Initialize position to 0

    	// Loop to read characters from the input until EOF
    	while ((c = getchar()) != EOF)
    	{
        	line[pos] = c;  // Store the current character in the line array

        	// If the character is a tab, expand it into spaces
        	if (c == '\t')
            		pos = expandtab(pos);

        	// If the character is a newline, print the current line and reset position
        	if (c == '\n')
        	{
            		printline(pos);
            		pos = 0;  // Reset position after printing the line
        	}
        	// If the position exceeds MAXCOL, fold the line
        	else if (++pos >= MAXCOL)
        	{
            		pos = getblank(pos);  // Find the last blank character before MAXCOL
            		printline(pos);       // Print the folded line
            		pos = newposition(pos); // Move the remaining characters to the start
        	}
    	}
    	return 0;  // Return 0 to indicate successful execution
}

// Function to expand tabs into spaces
uint32_t expandtab(uint32_t pos)
{
    	line[pos] = ' ';  // Replace the tab with a space

    	// Continue replacing positions until the position is aligned with the next tab stop
    	for (++pos; (pos < MAXCOL) && ((pos % TABVAL) != 0); ++pos)
        	line[pos] = ' ';  // Replace the current position with a space

    	// If the position exceeds the maximum column limit, print the line and return 0
    	if (pos >= MAXCOL)
    	{
        	printline(pos);  // Print the current line
        	return 0;        // Return 0 indicating the line has been printed
    	}
    	else
        	return pos;  // Return the new position after expanding the tab
}

// Function to print the current line up to the specified position
uint32_t printline(uint32_t pos)
{
    	uint32_t i;
    	for (i = 0; i < pos; ++i)
        	putchar(line[i]);  // Print each character of the line

    	// If the line has at least one character, print a newline character at the end
    	if (pos > 0)
        	putchar('\n');

    	return 0;
}

// Function to find the last blank character before a specified position
uint32_t getblank(uint32_t pos)
{
    	if (pos > 0)
        // Move backward to find the last space or tab before MAXCOL
        while (line[pos] != ' ' && line[pos] != '	')
            	--pos;

    	// If no blank character is found, return MAXCOL
    	if (pos == 0)
        	return MAXCOL;
    	else
        	return pos + 1;  // Return the position of the blank character plus one
}

// Function to adjust the position after folding a line
uint32_t newposition(uint32_t pos)
{
    uint32_t i, j;

    // If the position is invalid (out of range), return 0
    if (pos <= 0 || pos >= MAXCOL)
        return 0;
    else
    {
        i = 0;
        // Shift the remaining characters after the folded line to the start of the array
        for (j = pos; j < MAXCOL; ++j, ++i)
            line[i] = line[j];
    }
    //return i;  // Return the new position after folding
}
