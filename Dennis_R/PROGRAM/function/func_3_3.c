/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
 *
 * Author : Aditya Nathwani
 * Created : 3 February, 2025
 */

/* required header files */
#include <stdint.h>
#include <stdio.h>

#define MAXLINE 100
uint32_t index1 = 0;
char s[100] = {0};
uint32_t lim;
/* Function to read input */
uint32_t mgetline3() 
{
    	printf("\tExpands the given input in the form a-z-a or z-a-z.\n\n");


    	int ichar;

	char buff = getchar();
    	/* Read characters till EOF or newline */
    	while (index1 < lim - 1 && (ichar = getchar()) != EOF && ichar != '\n') 
	{
        	s[index1++] = ichar;
    	}

    	s[index1] = '\0';  // Null-terminate the string

    	return index1; // Return length of input string
}

/* start of void function */
void expand()
{
	uint32_t offset;
	uint32_t offsetop = 0;
	char start, end;
	uint32_t output[200] = {0};
	for ( offset = 0; offset < index1; offset++ )
	{
		/* looking for hyphen in the string */
		if ( s[offset] == '-' )
		{
			/* getting the character before the hyphen */
			if ( s[offset-1] >= 'a' && s[offset-1] <= 'z' )
			{
				start = s[offset-1];
				/* getting the character after the hyphen */
				if ( s[offset+1] >= 'a' && s[offset+1] <= 'z' )
				{
					end = s[offset+1];
					/* for ascending order */
					if ( start < end )
					{
						/* loop to print the sequence */
						while ( start <= end )
						{
							printf("%c",start++);
							//output[offsetop++] = start++;
						}
					}
					/* for descending order */
					else if ( start > end )
					{
						/* loop to print the sequence */
						while ( start >= end )
						{
							printf("%c",start--);
						}
					}
				}
			}
			/* similar condition for the capital letters */
			else if ( s[offset-1] >= 'A' && s[offset-1] <= 'Z' )
                        {
                                start = s[offset-1];
                                if ( s[offset+1] >= 'A' && s[offset+1] <= 'Z' )
                                {
                                        end = s[offset+1];
                                        if ( start < end )
                                        {
                                                while ( start <= end )
                                                {
                                                        printf("%c",start++);
                                                }
                                        }
                                        else if ( start > end )
                                        {
                                                while ( start >= end )
                                                {
                                                        printf("%c",start--);
                                                }
                                        }
                                }
                        }
			/* similar condition for digits */
			else if ( s[offset-1] >= '0' && s[offset-1] <= '9' )
                        {
                                start = s[offset-1];
                                if ( s[offset+1] >= '0' && s[offset+1] <= '9' )
                                {
                                        end = s[offset+1];
                                        if ( start < end )
                                        {
                                                while ( start <= end )
                                                {
                                                        printf("%c",start++);
                                                }
                                        }
                                        else if ( start > end )
                                        {
                                                while ( start >= end )
                                                {
                                                        printf("%c",start--);
                                                }
                                        }
                                }
                        }
		}
	}
}

void expansion()
{
	mgetline3();
	expand();
	printf("\n");
}

