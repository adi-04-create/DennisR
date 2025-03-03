/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */

/* required header files */
#include <stdio.h>
#include "header.h"

/* Define constants */
#define MAXLINE 1000
#define LIMIT 80

/* start of ngetline function */
uint32_t ngetline(char s[], uint32_t lim)
{
    	uint32_t i, c;
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

