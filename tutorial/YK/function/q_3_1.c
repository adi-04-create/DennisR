/* 
 * Write a furction xstrchr( ) which scans a string from
 * beginning to end in search of a character. If the character is
 * found it should retuen a pointer to the first occurrence of the
 * given character in the string. If the given character is not
 * found in the string, the function should return a NULL.
 *
 * Prototype : char *xstrchr( char *string,char ch );
 *
 * AUTHOR  : ADITYA NATHWANI
 * CREATED : 26 FEBRUARY, 2025
 */

/* required header files */
#include <stdio.h>

/* prototype decleration of function */
char *xstrchr(char *string, char ch);

/* start of main function */
int main()
{
	int index = 0;
	int ichar;
	char ch;
	char arr[50] = {0};

	/* getting a string from user */
	printf("Enter a String    : ");
	while (( ichar = getchar()) != EOF && ichar != '\n' && index < 49 )
	{
		arr[index++] = ichar;
	}
	arr[index] = '\0';

	/* getting a character from user */
	printf("Enter a Character : ");
	scanf("%c",&ch);

	/* calling xstrchr function */
	char *output = xstrchr(arr,ch);
	
	if ( output )
	{
		printf("'%c' found at %ld position\n",ch, output - arr);
	}
	else
	{
		printf("'%c' not found...\n",ch);
	}	
	return 0;
}
/* end of main function */

/* start of xstrchr function */
char *xstrchr(char *string,char ch)
{
	/* till we keep on getting string */
	while ( *string )
	{
		/* comparing value pointed with the character */
		if ( *string == ch )
		{
			return string;
		}
		string++;
	}
	return NULL;
}
/* end of xstrchr function */


