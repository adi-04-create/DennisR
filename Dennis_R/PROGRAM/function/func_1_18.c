/* trim_trailing_whitespace: This function removes spaces and tabs from the end of the string
 * Author: Aditya Nathwani
 * Created: 24, Dec, 2024 
 */

/* required header files */
#include <stdio.h>
#include <stdint.h>
#include "header.h"

/* start of trim function */
void trim()
{
	/* variable and array decleration */
	printf("Enter a string : ");
	uint16_t iChar;
	uint16_t str[100] = {0};
	uint16_t ilength = 0;

	/* buffer character for the main file while loop */
	char buff = getchar();
	
	/* while loop to get the string from user */
	while (( iChar = getchar()) != EOF && iChar != '\n' )
	{
		str[ilength] = iChar;
		ilength++;
	}

	printf("\n");

	/* to visually see the string entered by the user */
	printf("String entered by the user : ");
	for ( uint8_t offset = 0; offset < ilength ; offset++ )
	{
		if( str[offset] == ' ' )
		{
			printf("\\s");
		}
		else if( str[offset] == '\t' )
		{
			printf("\\t");
		}
		else
			printf("%c",str[offset]);
	}
	printf("\n");

	printf("Index before : %d",ilength);
	printf("\n");
	ilength++;
	uint32_t offset = ilength - 1;

	/* while loop to remove the trailing blank spaces and tabs */
	while( offset > 0 && str[offset - 1] == ' ' || str[offset - 1] == '\t' )
	{
		/* decreamenting the index and placing a null character */
		str[offset - 1] = '\0';
		offset--;
	}
	printf("Index after : %d",offset);
	printf("\n");

}
/* end of trim function */
