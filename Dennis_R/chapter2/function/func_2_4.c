/*function of an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. 
Author: Aditya Nathwani
created:7 jan 2025
modified:7 jan 2025 */

/* required header files */
#include<stdio.h>
#include <stdint.h>
#include"header.h"
#include"stdbool.h"

/* start of squeeze function */
void squeeze(char s1[],char s2[])
{
	/* variable decleration */
	uint32_t index1,index2,index3;

	/* index3 is index of string 2 */
	/* index1 is index of string 1 */
	/* index2 is index of output string */
	/* start of for loop */
	for(index3=0;s2[index3] !='\0';++index3)
	{
		for(index1=index2=0; s1[index1] !='\0' ; ++index1)
		{
			if(s1[index1] != s2[index3])
			{
				s1[index2++]=s1[index1];
			}
		}
	/* terminating character of output */	
	s1[index2]='\0';
	}
}
/* end of squeeze function */


/* start of main function */
void delete4()
{
        /* array and variable decleration and initialisation */
        char string1[100],string2[100];
        uint32_t index1,index2;
        index1=index2=0;
        char ch;
        printf("enter string1 : ");

        /* loop for getting the characters for first string */
        while ((ch = getchar()) != EOF &&  ch != '\n')
        {
                string1[index1++] = ch;
        }
        printf("enter string2:");

        /*loop for getting the characters for second string */
        while ((ch = getchar()) != EOF &&  ch != '\n')
        {
                string2[index2++] = ch;
        }

        /* calling of function */
        squeeze(string1,string2);
        printf("output string : %s\n",string1);
        //printf("string2:%s\n",string2);
        
}
/* end of main function */
