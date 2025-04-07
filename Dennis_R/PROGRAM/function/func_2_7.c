#include <stdint.h>
//required headers
#include<stdio.h>
#include"header.h"

void invert(uint32_t x,uint32_t inumber,uint32_t iposition){
	
	uint32_t mask;
	long long output;
	mask= ((1<<inumber)-1)<<iposition;

	uint32_t variable;

	variable = x ^ mask;
	printf("\noutput bit string:");
	binary(variable);
	

	return 0;
}	

/* void binary(uint32_t decimal){
	

	uint32_t i;
	for(i=15;i>=0;--i){
	unsigned uint32_t binary= (decimal >> i) & 1;
	printf("%u",binary);
	}
	printf("
");


} */


void bit_invert()
{

        uint32_t inumber,iposition;
        uint32_t input1;

        char input[32];

	char buff = getchar();
        printf("enter the value of first binary string   : ");
        fgets(input,32,stdin);
        input1 = strtoul(input,NULL,2);



        printf("\nenter the value of position you want to change the binary string:");
        scanf("%d",&iposition);

        printf("\nenter the value of the number of bits you want to change from the position given:");
        scanf("%d",&inumber);


        invert(input1,inumber,iposition);
}
