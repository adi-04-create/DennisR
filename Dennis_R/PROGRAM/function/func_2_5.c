/* the function about any(s1,s2), which returns the first location in a string s1where any character from the string s2 occurs, or -1 if s1 contains no characters from s2
Author: Aditya Nathwani
created:7 jan 2025
modified:7 jan 2025 */

/* required header files */
#include<stdio.h>
#include"header.h"
#include <stdint.h>

/* start of function */
uint32_t any(char s1[],char s2[])
{
	uint32_t index1,index2;
	for(index1=0;s2[index1] !='\0';++index1)
	{
		for(index2=0; s1[index2] !='\0' ; ++index2)
		{
			if(s1[index2] == s2[index1])
			{
				return index2+1;
			}
		}	
	
	}
	return -1;
}

/* start of main function */
void location_return()
{
        /* array and variable decleration and initialisation */
        char string1[100],string2[100];
        uint32_t index1,index2;
        index1=index2=0;
        char ch;
        printf("enter string1:");

	char buff = getchar();
        /* loop for getting the first string */
        while ((ch = getchar()) != EOF &&  ch != '\n')
        {
                string1[index1++] = ch;
        }
        printf("enter string2:");

//	char buff2 = getchar();
        /* loop for getting the second string */
        while ((ch = getchar()) != EOF &&  ch != '\n')
        {
                string2[index2++] = ch;
        }
        uint32_t result;

        /* calling of function */
        result = any(string1,string2);
        if(result != -1){
        printf("index of the matching character: \"%d\" (index starts from 1)\n",result);

        }
        else
        {
                printf("Value of function any(string1,string2) : %d\n",result);
        }
        
}
/* end of main function */
