/* required header files */
#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAXLINE 100

/* start of itob function 
 * Takes the number, the base value and the final array as input
 */
void itob(uint32_t input,char array[],uint32_t base)
{
    	uint32_t index,number;
    	index = 0;

	/* run the do while loop till the division of number reaches 0 */
    	do
    	{
        	number = input % base;

		/* here the number greater then 9 will be converted to hex */
        	array[index++] = (number <= 9)?number+'0':number+'a'-10;
    	}
	while((input/=base)>0);

	/* terminating character for the array */
    	array[index]='\0';

	/* generated number is in reverse order, so we have to again reverse it */
    	reverse(array);
}
/* end of itob function */

/* start of reverse function */
void reverse(char output[])
{
    	uint32_t index1,index2,char1;


    	for( index1=0,index2=strlen(output)-1; index1<index2; index1++,index2--)
	{
        	char1=output[index1],output[index1]=output[index2],output[index2]=char1;
	}
}
/* end of reverse function */

void conversion()
{
    uint32_t number,base;
    char str[MAXLINE];
    printf("Enter the number    : ");
    scanf("%d",&number);
    printf("Enter the base value:");
    scanf("%d",&base);
    /*number=42425;*/
    /*base=16;*/

    itob(number,str,base);

    printf("%s\n",str);

    
}
