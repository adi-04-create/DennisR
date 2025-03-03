/* Write a program to print a histogram of the frequencies of different characters in its input.
author: Aditya Nathwani
created: 31 December 2024
modified: 31 December 2024
*/

/* required header files */
#include <stdio.h>
#include "header.h"

#define MAX_CHAR 256  //Maximum number of possible characters (ASCII range)

/* start of main */
void func14()
{
	uint32_t c;
   	uint32_t freq[MAX_CHAR] = {0};  //Array to store the frequency of each character

    /* Read characters until EOF */
    	while ((c = getchar()) != EOF)
    {
	    freq[c]++;  //Increment the frequency of the character
    }

    //Print the histogram
    for (uint32_t i = 0; i < MAX_CHAR; i++)
    {
	    if (freq[i] > 0)
	    {
		    printf("Character '%c' (ASCII %d): ", i, i);
            	    for (uint32_t j = 0; j < freq[i]; j++)
	    {
		    printf("*");  //Print a '*' for each occurrence of the character
            }
            printf("\n");
        }
    }

    
}

