/*function to count words
Author: Aditya Nathwani
created:30 dec 2024
modified:30 dec 2024
*/

/* reqired header files */
#include <stdio.h>
#include"header.h"
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */


/* this function is to count word in the given input */
void  wordcounting()
{
	 /* variable decleration */
	 int iChar,iNline,iNword,iNchar, state;
	 state = OUT;

	 /* initialising variables */
	 iNline=iNword=iNchar= 0;
	 while ((iChar = getchar()) != EOF)
	 {
	 	++iNchar;
	 	if (iChar == '\n')
	 		++iNline;
	 	if (iChar == ' ' || iChar == '\n' || iChar == '\t')
	 		state = OUT;
	 	else if (state == OUT)
		{
	 		state = IN;
	 		++iNword;
	 	}
	 }
	 printf("total newline:%d\ntotal word: %d\ntotal character: %d\n",iNline,iNword,iNchar); 
}
/* end of function */
