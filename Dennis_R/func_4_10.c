/* An alternate organization uses getline to read an entire input line; this makes getch and  * ungetch unnecessary. Revise the calculator to use this approach.
 * Author: Aditya Nathwani
 * Created: 1 March, 2025
 */

/* Required header files */
#include "header.h"
#include <stdio.h>
#include "stdint.h"
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 100

// Function to process user input and perform calculations
void ExecuteCalculator1(void) 
{
    	char cLine[MAX_LINE_LEN];
    	uint16_t iLineLength;
    	int iOperand1, iOperand2;
    	char cOperator;

    	while (1) 
	{
        	printf("Enter expression: ");
        	iLineLength = get_line1(cLine, MAX_LINE_LEN);

        	// If EOF is encountered, exit the loop
        	if (iLineLength == 0) 
		{
            		printf("EOF encountered\n");
            		break;
        	}

        	// Process the input line
        	if (sscanf(cLine, "%d %c %d", &iOperand1, &cOperator, &iOperand2) == 3) 
		{
            		switch (cOperator) 
			{
                		case '+':
                    			printf("Result: %d\n", iOperand1 + iOperand2);
                    			break;
                		case '-':
                    			printf("Result: %d\n", iOperand1 - iOperand2);
                    			break;
                		case '*':
                    			printf("Result: %d\n", iOperand1 * iOperand2);
                    			break;
                		case '/':
                    			if (iOperand2 != 0)
                        			printf("Result: %d\n", iOperand1 / iOperand2);
                    			else
                        			printf("Error: Division by zero\n");
                    			break;
                		default:
                    			printf("Error: Invalid operator\n");
                    			break;
            		}
        	} 
		else 
		{
            		printf("Error: Invalid expression format\n");
        	}
    	}
}

// Function to read user-entered lines
uint16_t get_line1(char cLine[], uint16_t iMaxLineLen) 
{
    	int iChar;
    	uint16_t iIndex;

    	for (iIndex = 0; iIndex < iMaxLineLen - 1 && (iChar = getchar()) != EOF && iChar != '\n'; ++iIndex) 
	{
        	cLine[iIndex] = iChar;
    	}

    	if (iChar == '\n') 
	{
        	cLine[iIndex] = iChar;
        	++iIndex;
    	}

    	// Add a null terminator to mark the end of the string.
    	cLine[iIndex] = '\0';
    	return iIndex; // Returns the line length
}

