/* Program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
Author: Aditya Nathwani
Created: 30 December 2024
Modified: 30 December 2024*/

/* required header files */
#include <stdio.h>
#include "header_1_18.h"

/* start of main function */
int main()
{
    	/* variable decleration and initialisation */
	/*int c,i;
	int arr[300];
	int index = 0;
    	bool state = true;*/

    	/* While loop to read characters from standard input until EOF is reached */
    	/*while ((c = getchar()) != EOF && c != '\n')
    	{
		arr[index] = c;
		index++;
	}
	printf("Index with trailing blanks : %d\n",index);
	
	while ( index > 0 )
	{
		if ( arr[index] == '\0' )
		{
			index--;
		}
	}
	printf("Index without trailing blanks : %d\n",index);*/

	trim();
    	return 0; //End of program
}

