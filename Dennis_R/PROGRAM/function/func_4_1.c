/* Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
 * Author : Aditya Nathwani
 * Created : 1 February, 2025
 */

/* required header files */
#include <stdio.h>
#include <stdint.h>
/* start of strindex function */
void strindex()
{
	/* variable and array decleration */
	int ichar,index;
	int array[30] = {0};
	char letter;

	char buff = getchar();
	/* getting string from user */
	printf("Enter a string : ");
	while(( ichar = getchar()) != EOF && ichar != '\n' )
	{
		array[index] = ichar;
		index++;
	}

	//char buff2 = getchar();
	/* getting character from user */
	printf("Enter a character : ");
	//letter = getchar();
	scanf("%c",&letter);

	/* comparing the character with the string from the right side */
	for( int offset = index; offset >= 0; offset-- )
	{
		if ( array[offset] == letter )
		{
			printf("%c occures rightmost in the string at %d position.\n",letter,offset);
			break;
		}
		/* if we do not get the character */
		else if( offset == 0 )
		{
			printf("%c did not occure in the string.\n",letter);
		}
	}
}
		
/* end of strindex function */
