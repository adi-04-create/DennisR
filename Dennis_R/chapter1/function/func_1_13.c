/* required header files */
#include <stdio.h>
#include "header.h"

/* start of function */
void function()
{

	/*Variable declaration and initialization*/
    	uint32_t c;
    	uint32_t iWordlength = 0;
    	uint32_t jWordcount = 0;
    	uint32_t max = 0;
    	uint32_t freq[1000] = {0};


    	printf("Enter a string:\n");


    	/*The loop will continue until the user enters EOF (End Of File)*/
    	while ((c = getchar()) != EOF)
    	{
        	/*If the character is not a space, tab, or newline, it's part of a word*/
        	if (c != '\n' && c != '\t' && c != ' ')
        	{
			iWordlength++;
        	}
        	else
        	{
            		/*If a space or other separator is encountered, update the frequency of the word length*/
            		freq[iWordlength]++;

            		/*Update the maximum word length if needed*/
            		if (iWordlength > max)
            		{
                		max = iWordlength;
            		}

            		/*Reset the word length counter to 0 for the next word*/
            		iWordlength = 0;
        	}
    	}

    	/*Output the histogram of word lengths*/

    	for (jWordcount = 0; jWordcount <= max; jWordcount++)
    	{
        	/*Print the word length (index)*/
        	printf("%d : ", jWordcount);

        	/*For each word length, print stars (*) corresponding to the frequency*/
        	for (uint32_t i = 0; i < freq[jWordcount]; i++)
        	{
            		printf("*");
        	}

        	/*Move to the next line after printing stars for each word length*/
        	printf("\n");
    	}
}
/* end of function */
