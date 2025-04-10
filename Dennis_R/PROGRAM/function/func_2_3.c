/* required header files */
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

/* start of power function */
uint32_t Power(uint32_t n)
{
    	long long iPower;
    	for (iPower = 1; n > 0; n--)
    		iPower = iPower * 16;

    	return iPower;
}
/* end of power function */

/* start of hextointeger function */
uint32_t HextoInteger(char s[])
{
	/* variable decleration and initialisation */
	uint32_t value=0;
        uint32_t wordcount=0;
        uint32_t index=0;
        uint32_t powervalue=0;
        uint32_t charvalue=0;
	if (s[0]== '0' && ( s[1]== 'x' || s[1]== 'X' ))
	{
        	s+=2;
        }
	while(s[wordcount] !='\0')
        {
        	wordcount++;
        }

	for (index=0;index < wordcount;++index)
	{
        	powervalue = Power( wordcount-1-index );

		if(s[index]>='0' && s[index]<='9')
		{
        		charvalue = s[index]-'0';
        	}
		else if(s[index]>='a' && s[index]<='f')
		{
        		charvalue = s[index]- 'a' + 10;
		}
		else if (s[index]>='A' && s[index]<='F')
		{
			charvalue = s[index]- 'A' + 10 ;
		}
		else 
		{
                	printf("invalid character:%c\n",s[index]);
                	return -1;
        	}
        
        	value = ((powervalue) * (charvalue)) + value ;
	}
return value;
}
/* end of hextointeger function */

/* getting the hex number as input */
void hex()
{       char input[100];
        uint32_t index = 0;
        char ch;
        long result;
        printf("enter hex number(ctrl d to exit):\n");

	char buff = getchar();
        // Read input character by character using getchar
        while ((ch = getchar()) != EOF &&  ch != '\n')
        {
                input[index++] = ch;
        }
        // input[index] = ' ';

        // Convert the input hexadecimal string to integer.
        result = HextoInteger(input);
        if (result != -1)
        {
                printf("integer value is: %d\n", result);
        }

      

} 
/* input function */
