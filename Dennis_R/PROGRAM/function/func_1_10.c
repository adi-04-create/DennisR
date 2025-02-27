#include <stdint.h>
/* required header files */
#include<stdio.h>
#include "header.h"

/* start of function */
void find()
{
	printf("Write a program to copy its input to its output, replacing each tab by \\t, each backspace by \\b, and each backslash by \\\. This makes tabs and backspaces visible in an unambiguous way.\n\n");
      	uint32_t c;
      	while ((c = getchar()) != EOF)
	{
        	if (c == '\t')
		{
            		/* If the character is a tab, print 	 */
            		printf("\\t");
        	}
		else if (c == '\b')
		{
            		/* If the character is a backspace, print  */
            		printf("\\b");
        	}
		else if (c == '\n')
		{
			/* If the character is a newline, print 
 */
			printf("\\n");
		}
		else if (c == ' ')
                {
                        /* If the character is a space, print \s */
                        printf("\\s");
                }
		else if (c == '\\')
		{
            		/* If the character is a backslash, print */
            		printf("\\");
        	} 
		else
		{
            		/* Otherwise, print the character as it is */
            		putchar(c);
        	}
    	}
}
/* end of function */
