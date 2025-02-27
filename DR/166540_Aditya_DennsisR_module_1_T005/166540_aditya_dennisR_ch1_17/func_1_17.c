/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */

/* required header files */
#include <stdio.h>
#include "header_1_17.h"

/* Define constants */
#define MAXLINE 1000
#define LIMIT 80

/* start of ngetline function */
int ngetline(char s[], int lim)
{
    	int i, c;
    	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	    	s[i] = c;

    /* If a newline is encountered, store it in the array and increment the index */
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    /* Null-terminate the string */
    s[i] = '\0';

    return i;  /* Return the length of the string (including newline if it was read) */
}


/* start of main */
void longerline()
{
        printf("\tto print all input lines that are longer than 80 characters.\n\n");
          /* Declare variables */
        int len;
        char line[MAXLINE];

        while ((len = ngetline(line, MAXLINE)) > 0)
        {
        if (len > LIMIT)
                printf("%s", line);  /* Print the line */
    }

    
}
/* end of main */
