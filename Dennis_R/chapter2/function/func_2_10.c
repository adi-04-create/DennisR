/* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead  * of if-else.
 *
 * Author : Aditya Nathwani
 * Created : 10 January, 2025
 */

/* required header files */
#include <stdio.h>
#include <stdint.h>

/* start of function */
void upper2lower()
{
	printf("\n\tConvert Uppercase to Lowercase without if-else\n\n");
	uint16_t ichar;
	uint16_t index = 0;
	uint16_t array[30] = {0};
	printf("Enter a string : ");
	
	while(( ichar = getchar()) != EOF && ichar != '\n' )
	{
		array[index++] = ichar;
	}

	for( uint32_t offset = 0;offset < index; offset++ )
	{
		( array[offset] >= 'A' && array[offset] <= 'Z' ) ? ( putchar( array[offset] + 32 ) ) : ( putchar( array[offset] ) );
//		( array[offset] >= 'a' && array[offset] <= 'z' ) ? ( putchar( array[offset] - 32 ) ) : ( putchar( array[offset] ) );
	}

	printf("\n");
//	return 0;
}
/* end of function */
/*
void uppertolower()
{
	upper2lower();
}*/
