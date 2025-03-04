#include <stdint.h>
/* Write a program that prints its input one word per line
Author: Aditya Nathwani
created: 30 December 2024
modified: 30 December 2024
*/

/* required header files */
#include<stdio.h>
#include "header.h"
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* start of function */
void newline()
{
	printf("	Prints the input one word per line.\n\n");
	uint32_t c, state;
	state = OUT;
<<<<<<< HEAD
	
=======
	char a = getchar();	
>>>>>>> origin/master
	while ((c = getchar()) != EOF)
	{
        	if (c == ' ' || c == '	' || c == '\n') 
		{
            		if (state == IN)
			{
        	        	putchar('\n');  /* Print a new line when a word ends */
                		state = OUT;    /* We are outside a word now */
            		}
        	}
		else
		{
            		if (state == OUT)
			{
                		state = IN;    /* We're inside a word now */
            		}
            		putchar(c);  /* Print the character */
        	}
    	}
}
