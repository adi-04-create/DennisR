/*
 * Write a function xstrstr( ) that will scan a string for the
 * occurance of a given sub-string
 *
 * prototype : char *xstrstr( char *string1, char *string2 )
 *
 * AUTHOR   : ADITYA NATHWANI
 * CREATED  : 26 FEBRUARY, 2025
 */

/* required header files */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* start of xstrstr function */
char *xstrstr( char *string1, char *string2 )
{
	/* variable decleration and initialisation
	 * array decleration and initialisation */
	char arr[50] = {0};
	uint16_t index = 0;
	uint16_t index1 = 0;
	uint16_t offset = 0;
	uint8_t op_arr[20] = {0};

	/* for ( i=0;i<strlen(string1);i++ ) */
	while ( *string1 )
	{
		offset++;
		if ( *string1 == *string2 )
		{
			op_arr[index1++] = offset;
			arr[index++] = *string1;
			string1++;
			string2++;
			if ( *string1 != *string2 )
			{
			//	printf("%s\n",op_arr);
				break;
			}
		}
		else if ( *string1 != *string2 )
		{
			string1++;
		}
		/*else
		{
			return NULL;
		}*/
		/*else if ( *string1 != *string2 )
		{
			return NULL;
		}*/
	}
	
	printf("Matched string is : %s\n",arr);
	printf("Index in string 1 : %d\n",*op_arr);
}
/* end of xstrstr function */

/* start of main function */
int main()
{
	uint16_t index1 = 0;
	uint16_t index2 = 0;
	char ichar1,ichar2;
	char arr1[50] = {0};
	char arr2[50] = {0};

	printf("Enter string 1    : ");
	while ((ichar1 = getchar()) != EOF && ichar1 != '\n' && index1 < 49) 
	{
        	arr1[index1++] = ichar1;
    	}

	printf("Enter string 2    : ");
        while ((ichar2 = getchar()) != EOF && ichar2 != '\n' && index2 < 49)
        {
                arr2[index2++] = ichar2;
        }

	/* calling of xstrstr function */
	xstrstr(arr1, arr2);

	return 0;
}
/* end of main function */
