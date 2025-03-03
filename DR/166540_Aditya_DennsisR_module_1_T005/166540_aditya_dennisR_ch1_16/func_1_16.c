/* required header files */
#include <stdio.h>
#include "header_1_16.h"

/* Define constant for maximum line length */
#define MAXLINE 1000
/*
* mgetline: Reads a line of input from stdin, and returns the length of the line.
* 's[]' is the array to store the line, and 'lim' is the maximum allowed length of the line.
*/
int mgetline(char s[], int lim)
{
    	int i, c;

    	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        	s[i] = c;

    	/* If a newline is encountered, store it as well */
    	if (c == '\n')
    	{
        	s[i] = c;
        	++i;
    	}

    	s[i] = '\0';  /* Null-terminate the string to mark the end of the line */
    	return i;     /* Return the length of the line (including newline if present) */
}
/*
* copy: Copies the string from 'from' to 'to'.
* The function stops when it reaches the null-terminator of the 'from' string.
*/
void copy(char to[], char from[])
{
    	int i = 0;
    	while ((to[i] = from[i]) != '\0')
        	++i;
}

/* start of main function */
void longest_line()
{
        printf("\tTo print the longest line\n\n");
        int len, max;
        char line[MAXLINE], maxline[MAXLINE];
        max = 0;

        /* Read lines until EOF is reached */
        while ((len = mgetline(line, MAXLINE)) > 0)
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
