/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 *
 * Author : Aditya Nathwani
 * Created : 10 January, 2025
 */

/* required header files */
#include<stdio.h>
#include"header.h"
#include <stdint.h>
/* start of setbit function */
//void setbit(uint32_t x,uint32_t inumber,uint32_t iposition, uint32_t y)
void setbit()
{	
	/* variable decleration, array decleration */
        uint32_t inumber,iposition,index1,index2;
        uint32_t input1,input2;
        char input[32];

        printf("enter the value of first binary string:");
        fgets(input,32,stdin);

        /* converting binary string to decimal number */
        input1 = strtoul(input,NULL,2);

        printf("\nenter the value of second binary string:");
        fgets(input,32,stdin);

        /* converting binary string to decimal number */
        input2 = strtoul(input,NULL,2);

        printf("\nenter the value of position you want to change the binary string:");
        scanf("%d",&iposition);

        printf("\nenter the value of the number of bits you want to change from the position given:");
        scanf("%d",&inumber);
	/* variable decleration */
	uint32_t mask;
	long long output;

	/* creating a mask according to number of bits and starting position of bits */
	mask= ((1<<inumber)-1)<<iposition;

	/* variable decleration */
	uint32_t variable1,variable2,variable3;

	/* working with the mask */
	variable1 = input2 & mask;
	variable2 = input1 & (~(mask));
	variable3 = variable1 | variable2;
	printf("\noutput bit string:");
	binary(variable3);
	return 0;
}	
/* end of setbit function */

/* start of binary function */
void binary(uint32_t decimal)
{
	/* variable decleration */
	uint32_t i;

	/* printing output as binary */
	for(i=15;i>=0;--i)
	{
		uint32_t binary= (decimal >> i) & 1;
		printf("%u",binary);
	}
	
	/*if ( decimal % 2 == 0 )
		printf("0");
	else
		printf("1");*/

	printf("\n");
}
/* end of binary function */

