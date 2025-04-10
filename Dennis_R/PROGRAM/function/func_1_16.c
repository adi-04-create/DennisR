#include <stdint.h>
/* required header files */
#include <stdio.h>
#include "header.h"

/* Define constant for maximum line length */
#define MAXLINE 1000
/*
* mgetline: Reads a line of input from stdin, and returns the length of the line.
* 's[]' is the array to store the line, and 'lim' is the maximum allowed length of the line.
*/
uint32_t mgetline4(char s[], uint32_t lim)
{
    	uint32_t i, c;

	uint32_t buff = getchar();
    	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        	s[i] = c;

    	/* If a newline is encountered, store it as well */
    	if (c == '\n')
    	{
        	s[i] = c;
        	++i;
    	}

    	s[i] = ' ';  /* Null-terminate the string to mark the end of the line */
    	return i;     /* Return the length of the line (including newline if present) */
}
/*
* copy: Copies the string from 'from' to 'to'.
* The function stops when it reaches the null-terminator of the 'from' string.
*/
void copy(char to[], char from[])
{
    	uint32_t i = 0;
    	while ((to[i] = from[i]) != ' ')
        	++i;
}

/* start of main function */
void longest_line()
{
        printf("	To print the longest line\n\n");
        uint32_t len, max;
        char line[MAXLINE], maxline[MAXLINE];
        max = 0;

        /* Read lines until EOF is reached */
        while ((len = mgetline4(line, MAXLINE)) > 0)
        {
                /* If this line is longer than previous longest, update max and copy the line */
                if (len > max)
                {
                        max = len;
                        copy(maxline, line);
                }
        }

        /* If we have read any lines, print the longest line */
        if (max > 0)
                printf("%s", maxline);

       
}
