/* Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
   Author: Bhavya Jyotishi
   Cretaed: 01/03/2025
*/

// Required header files
#include <stdint.h>
#include "header.h"
#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

static int cLastChar = ' '; // Static variable to store last read character

// Function to process user input
void ProcessInput1(void) 
{
    	char cString[100];
    	int iToken;

    	while ((iToken = GetOp(cString)) != EOF) 
	{
        	if (iToken == NUMBER)
            		printf("Number: %s\n", cString);
        	else
            		printf("Operator: %c\n", iToken);
    	}
}

// Function to get the next operator or numeric operand
int GetOp(char cString[]) 
{
    	int iIndex = 0;
    	int cChar;

    	// Skip whitespace
    	while ((cString[0] = cChar = (cLastChar ? cLastChar : getchar())) == ' ' || cChar == '\t')
        	cLastChar = 0;  // Clear stored character if used

    	cString[1] = '\0'; // Null-terminate if it's an operator

    	// If not a number or decimal, return operator
    	if (!isdigit(cChar) && cChar != '.') 
	{
        	cLastChar = 0; // Reset stored char since it's used
        	return cChar;
    	}

    	// Read integer part
    	if (isdigit(cChar)) 
	{
        	while (isdigit(cString[++iIndex] = cChar = getchar()))
            	;
    	}

    	// Read decimal part if exists
    	if (cChar == '.') 
	{
        	while (isdigit(cString[++iIndex] = cChar = getchar()))
        	;
    	}

    	cString[iIndex] = '\0'; // Null terminate the string

    	// Store the last read character
    	cLastChar = cChar;

    	return NUMBER; // Return token type
}

