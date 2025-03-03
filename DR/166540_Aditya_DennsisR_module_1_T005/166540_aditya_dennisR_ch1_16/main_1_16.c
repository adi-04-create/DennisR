/*Exercise 1.16 - Print length of arbitrary long input line.c
Author: Aditya Nathwani
created: 2 Jan 2025
modified: 2 Jan 2025*/

/* required header files */
#include <stdio.h>
#include "header_1_16.h"
/* Define constant for maximum line length */
#define MAXLINE 1000

/* start of main function */
int main()
{
/*	printf("\tTo print the longest line\n\n");
    	int len, max;
    	char line[MAXLINE], maxline[MAXLINE];
    	max = 0;
*/
    	/* Read lines until EOF is reached */
  /*  	while ((len = mgetline(line, MAXLINE)) > 0)
    	{
    */    	/* If this line is longer than previous longest, update max and copy the line */
      /*  	if (len > max)
        	{
            		max = len;
            		copy(maxline, line); 
        	}
	}
*/
    	/* If we have read any lines, print the longest line */
  /*  	if (max > 0)
        	printf("%s", maxline);
*/
	longest_line();
    	return 0;
}
