/* Write a recursive version of the function reverse(s), which reverses the string s in place.
 *
 * Author  : Aditya Nathwani
 * Created : 25 February, 2025
 */

/* required header files */
#include <stdio.h>
#include <stdint.h>
void reverse_func()
{
	uint32_t index = 0;
	uint32_t ichar;
	uint32_t array[50] = {0};

	printf("Enter a string : ");
	while (( ichar = getchar()) != EOF )
	{
		array[index++] = ichar;
	}

//	printf("Entered String : %ls",array);
	printf("Output String  : ");
	for ( int offset = index; offset >= 0; offset-- )
	{
		printf("%c",array[offset]);
	}
	printf("\n");
}
