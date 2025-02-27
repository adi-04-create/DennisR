/* funtion of loop  equivalent to the for loop above without using && and ||
Author: Aditya Nathwani
created:3 jan 2025
modified:3 jan 2025 */

/* for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) */

/* required header files */
#include "header.h"
#include <stdint.h>
#include <stdio.h>
#define lim 7

/* start of function */
void eqloop()
{
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
