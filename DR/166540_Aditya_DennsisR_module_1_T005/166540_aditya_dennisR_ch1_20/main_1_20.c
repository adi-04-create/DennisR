/* Program to remove trailing blanks and tabs from each line of input,and to delete entirely blank lines.
Author: Aditya Nathwani
Created: 30 December 2024
Modified: 30 December 2024*/

/* required header files */
#include <stdio.h>  
#include <stdbool.h>

/* start of main */
int main()
{
    	/* variable decleration */
    	int c;
    	bool state = true;

    	/* While loop to read each character from input until EOF is encountered */
    	while ((c = getchar()) != EOF)
    	{
        	//Check if the character is a tab
        	if (c == '\t')
        	{
            		if (state)
            		{
                		printf(" ");
                		state = false;
            		}
        	}
        	else
        	{
            		state = true;
            		printf("%c", c);
        	}
    	}

    return 0;
}
