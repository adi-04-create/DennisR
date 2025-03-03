/* Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their propert * ies ought to be if an EOF is pushed back, then implement your design.
 * Author : Aditya Nathwani
 * Created: 1 March, 2025
 */

/* Required header files */
#include "header.h"
#include <stdio.h>

#define MAX_WORD_LENGTH 100

char cBuffer1 = 0; // Single-character buffer

// Function to process words and print their first character
void ProcessCharacter1(void) 
{
    	char cWord[MAX_WORD_LENGTH]; // Buffer to store words
    	int iIndex = 0;
    	int cChar;

    	while ((cChar = GetCharacter2()) != EOF) 
	{
        	if (cChar == '\n' || cChar == ' ' || cChar == '\t') 
		{
            		if (iIndex > 0) 
			{
                		cWord[iIndex] = '\0'; // Null terminate the word
                		printf("%c\n", cWord[0]); // Print first character of the word
                		iIndex = 0; // Reset for next word
            		}
        	} 
		else 
		{
            		cWord[iIndex++] = cChar; // Store character in word buffer
        	}
    	}

    	// Handle last word if input does not end with a newline
    	if (iIndex > 0) 
	{
        	printf("%c\n", cWord[0]);
    	}

printf("EOF encountered\n"); // Print when EOF is encountered
}

// Function to get a (possibly pushed back) character
int GetCharacter2(void) 
{
    	if (cBuffer1 != 0) 
	{
        	int temp = cBuffer1;
        	cBuffer1 = 0;
        	return temp;
    	}
    	return getchar();
}

// Function to push a character back into input
void UngetCharacter2(int cChar) 
{
    	if (cBuffer1 != 0) 
	{
       		printf("UngetCharacter: Too many characters\n");
    	} 
	else 
	{
        	cBuffer1 = cChar;
    	}	
}

