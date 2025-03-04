/*
 * Add commands for handling variables. (It's easy to provide twenty-six variables with singl * e-letter names.) Add a command for the most recently printed value. 
 * Author: Aditya Nathwani
 * Created: 1 March, 2025
 */


/* Required header files */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

#define MAXOP 100	/* Maximum size of operand or operator */
#define MAXVAL 100	/* Maximum depth of the value stack */
#define BUFSIZE 100	/* Buffer size for ungetch function */
#define NUMBER '0'


static int StackPos = 0;
static double ValueStack[MAXVAL];

static char Buffer[BUFSIZE];
static int BufferPos = 0;

static double LastPrintedValue = 0.0;
static double Variables[26] = {0};

/* Function to execute the reverse Polish calculator */
void ExecuteCalculator() 
{
    	int iType, iVar = 0;
    	double dOperand2;
    	char cToken[MAXOP];

    	while ((iType = GetOperator(cToken)) != EOF) 
	{
        	switch (iType) 
		{
            		case NUMBER: // If the token is a number, push it onto the stack
                		Push(atof(cToken));
                		break;
            		case '+': // Addition operation
                		Push(Pop() + Pop());
                		break;
            		case '*': // Multiplication operation
                		Push(Pop() * Pop());
                		break;
            		case '-': // Subtraction operation
                		dOperand2 = Pop();
                		Push(Pop() - dOperand2);
                		break;
            		case '/': // Division operation with zero check
                		dOperand2 = Pop();
                		if (dOperand2 != 0.0)
                    			Push(Pop() / dOperand2);
                		else
                    			printf("error: zero divisor\n");
                		break;
            		case '=': // Assignment operation for variables
                		Pop();
				if (iVar >= 'A' && iVar <= 'Z') 
				{
                    			Variables[iVar - 'A'] = Pop();
		    			Push(Variables[iVar - 'A']);
               			}
				else
                    			printf("error: invalid variable name\n");
                		break;
            		case '\n': // Print the result of the operation
                		LastPrintedValue = Pop();
                		printf("\t%.8g\n", LastPrintedValue);
                		break;
	    		case 'a':  // Command to print all variables
    				PrintVariables();
        			break;
	    		default:
	        		if (iType >= 'A' && iType <= 'Z') 
				{
        				Push(Variables[iType - 'A']);  // Retrieve and PUSH the variable onto the stack
                		} 
				else if (iType == 'l') 
				{
       					Push(LastPrintedValue);
   				} 
				else 
				{
   	        			printf("error: unknown command %s\n", cToken);
    	        		}
    				break;

        	}
        	iVar = iType; // Store last used variable/operator
    	}
}

// Function to print all variables
void PrintVariables() 
{
    	printf("Stored Variables:\n");
    	for (char c = 'A'; c <= 'Z'; c++) 
	{
        	if (Variables[c - 'A'] != 0) 
		{  // Print only non-zero variables
            		printf("%c = %.8g\n", c, Variables[c - 'A']);
        	}
    	}
}


// Function to push a value onto the stack
void Push(double dValue) 
{
    	if (StackPos < MAXVAL)
        	ValueStack[StackPos++] = dValue;
    	else
        	printf("error: stack full, can't push %g\n", dValue);
}

// Function to pop a value from the stack
int Pop() 
{
    	if (StackPos > 0)
        	return ValueStack[--StackPos];
    	else 
	{
        	printf("error: stack empty\n");
        	return 0.0;
    	}
}

// Function to get the next operator or operand
int GetOperator(char cToken[]) 
{
    	int i = 0, c, NextChar;

    	while ((cToken[0] = c = GetCharacter()) == ' ' || c == '\t')
        ; // Skip spaces and tabs

    	cToken[1] = '\0';

    	if (!isdigit(c) && c != '.')
        	return c; // Return operator

    	if (c == '-') 
	{ // Handle negative numbers
        	NextChar = GetCharacter();
        	if (!isdigit(NextChar) && NextChar != '.') 
		{
            		UngetCharacter(NextChar);
            		return c;
        	}
        	cToken[i++] = c;
        	c = NextChar;
    	}

    	if (isdigit(c) || c == '.') 
	{ // Read number
        do 
	{
            	cToken[i++] = c;
        } 
	while (isdigit(c = GetCharacter()) || c == '.');
    	}

    	cToken[i] = '\0';

    	if (c != EOF)
        	UngetCharacter(c); // Push back extra character

    	return NUMBER;
}

// Function to get a character from input or buffer
int GetCharacter(void) 
{
    	return (BufferPos > 0) ? Buffer[--BufferPos] : getchar();
}

// Function to push a character back into the buffer
void UngetCharacter(int c) 
{
    	if (BufferPos >= BUFSIZE)
        	printf("ungetch: too many characters\n");
    	else
        	Buffer[BufferPos++] = c;
}

