#include <stdint.h>

/* reqired header file */
#include <stdio.h>
#include "header.h"
/* count the input of newline tabs and blankspace */
void char_count()
{
	/* decleration and initialisation of variables */
        uint32_t c, nl, nt, nb,nc, state;
        nl = nt = nb = nc = 0;

        while ((c = getchar()) != EOF)
	{
		/* counting characters */
        	++nc;

		/* new lines */
        	if (c == ' ') 
        		++nl;
		/* tabs */
        	if (c == '	')
        		++nt;
		/* blank spaces */
        	if (c == ' ')
        		++nb;
        }
   
        printf("newlines: %dtabs: %dblanks: %dtotal character: %d", nl, nt, nb,nc);
}
/* end of function */
