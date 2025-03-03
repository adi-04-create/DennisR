/* trim_trailing_whitespace: This function removes spaces and tabs from the end of the string
 * Author: Meet
 * Created: 24, Dec, 2024 */
#include <stdio.h>
#include "header.h"
void trim()
{
	printf("Enter a string : ");
	int iChar;
	int str[100] = {0};
	int ilength = 0;
	while (( iChar = getchar()) != EOF && iChar != '\n' )
	{
		str[ilength] = iChar;
		ilength++;
	}
	printf("Index before : %d",ilength);

	int offset = ilength;
	while( offset > 0 && str[offset - 1] == ' ' )
	{
		str[offset - 1] = '\0';
		offset--;
	}
	printf("Index after : %d\n",offset);

}
