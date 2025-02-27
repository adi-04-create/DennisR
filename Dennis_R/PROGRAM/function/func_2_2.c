#include <stdint.h>
/* funtion of loop  equivalent to the for loop above without using && and ||
Author: Aditya Nathwani
created:3 jan 2025
modified:3 jan 2025 */

/* for (i=0; i < lim-1 && (c=getchar()) != '
' && c != EOF; ++i) */

/* required header files */
#include "header.h"
#include <stdio.h>
#define lim 7

/* start of function */
void eqloop()
{
	printf("\n\tfor loop equivalent to\nfor (i=0; i < lim-1 && (c=getchar()) != ' ' && c != EOF; ++i)\n\n");
	/* variable and array decleration */
	uint32_t index, ichar;
        char s[lim];
  	index=0;
	/* while loop */
        while(index<lim-1)
	{
		if((ichar=getchar()) != '\n')
	      	{
		      	if(ichar != EOF)
		      	{
			      	s[index] = ichar;
		      	}
              	}
              	index++;
        }	
	printf("%s\n",s);
	printf("%d\n",index);
}
/* end of function */
