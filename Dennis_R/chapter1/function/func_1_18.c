/* trim_trailing_whitespace: This function removes spaces and tabs from the end of the string
 * Author: Meet
 * Created: 24, Dec, 2024 */
#include <stdio.h>
#include "header.h"
void trim()
{
	printf("Enter a string : ");
	uint32_t iChar;
	uint32_t str[100];
	uint32_t ilength = 0;
	while (( iChar = getchar()) != EOF )
	{
		str[ilength] = iChar;
		ilength++;
	}

    	//find the length of the string
    	/*while (str[ilength] != '\0')
	{
        	ilength++;
    	}*/

    	//remove trailing spaces and tabs
    	while (ilength > 0 && (str[ilength - 1] == ' ' || str[ilength - 1] == '\t' || str[ilength - 1] == '\n'))
	{
        	ilength--;
    	}

    //null-terminate the string after trimming
    	str[ilength] = '\0';
}
