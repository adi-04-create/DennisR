
/* reqired header file */
#include <stdio.h>
#include "header.h"
/* count the input of newline tabs and blankspace */
void wordcounting()
{
	/* decleration and initialisation of variables */
        int c, nl, nt, nb,nc, state;
        nl = nt = nb = nc = 0;

        while ((c = getchar()) != EOF)
	{
		/* counting characters */
        	++nc;

		/* new lines */
        	if (c == '\n') 
        		++nl;
		/* tabs */
        	if (c == '\t')
        		++nt;
		/* blank spaces */
        	if (c == ' ')
        		++nb;
        }
   
        printf("newlines: %d\ntabs: %d\nblanks: %d\ntotal character: %d\n ", nl, nt, nb,nc);
}
/* end of function */
