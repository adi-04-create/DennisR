/* Adapt the ideas of printd to write a recursive version of itoa; that is, convert an intege * r into a string by calling a recursive routine.
 * Author: Aditya NAthwani
 * Created: 1 March, 2025
 */

/* Required header files */
#include "header.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAXLEN 100

// Recursive function to convert an integer to a string
void Itoaa(int32_t iNum, char cStr[]) 
{
    	static int iIndex = 0;

    	if (iNum / 10) 
	{
        	Itoaa(iNum / 10, cStr);
    	} 
	else 
	{
        	iIndex = 0;  
        	if (iNum < 0) 
		{
            		cStr[iIndex++] = '-';
        	}
    	}

    
	cStr[iIndex++] = '0' + abs(iNum % 10);
    
	cStr[iIndex] = '\0';
}

// Function to take user input and print the converted string
void ExecuteItoa(void) 
{
    	int32_t iNum;
    	char cStr[MAXLEN];

    	printf("Enter an integer: ");
    	scanf("%d", &iNum);

    	Itoaa(iNum, cStr);
    	printf("Converted String: %s\n", cStr);
}

