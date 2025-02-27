#include <stdint.h>
/* funtion to replace multiple blanks in single blank
Author: Aditya Nathwani
created:30 dec 2024
modified:30 dec 2024 */

/* required header files */
#include <stdio.h>
#include "header.h"
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* start of function */
void singleblank()
{
	printf("Replace multiple blanks with single blanks."); 
    	uint32_t iC, iState;

    	iState = OUT;

    	while ((iC = getchar()) != EOF)
	{
        	if (iC == ' ' || iC == '	' || iC == ' ')
		{
            		if (iState == OUT)
			{
                		putchar(iC);
                		iState = IN;  // We are inside a blank space
            		}
            	// If we're already in the state IN (inside blanks), do nothing
        	}
		else if (iC == '	')
		{
			if (iState == OUT)
			{
				putchar(iC);
				iState = IN;
			}
		}
		else
		{
            		putchar(iC);
            		iState = OUT; // We're outside a word
        	}
    	}
    	return 0;
}
/* end of function */
