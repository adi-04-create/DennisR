#include <stdint.h>
//required headers
#include<stdio.h>
#include"header.h"

void rightrot(uint32_t x,uint32_t inumber){

        uint32_t mask;
	
        uint32_t variable1,variable2,variable3,variable;
        long long output;
	/* creating a mask of desired numbers */
        mask= ((1<<inumber)-1) ;

	
	variable1= mask & x;
	variable2= variable1 << (16 - inumber) ;
	variable3= x >> inumber;
	variable= variable2 | variable3 ;

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


void right_rotate(){

        uint32_t inumber;
        uint32_t input1;

        char input[32];

	char buff = getchar();
        printf("enter the value of first binary string  : ");
        fgets(input,32,stdin);
        input1 = strtoul(input,NULL,2);




        printf("\nenter the number you want to rotate right the bit string : ");
        scanf("%d",&inumber);


        rightrot(input1,inumber);
       



}
