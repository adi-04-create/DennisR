#include <stdint.h>
#include<stdio.h>
#include"header.h"


uint32_t bitcount(uint32_t x){

	uint32_t b;

	while(x!=0){
		x&=x-1;
		   b++;}
	printf("number of 1's in the input is %d\n",b);
	return 0;	
}

void count(){

        char i[100];
        uint32_t input;
        fgets(i,100,stdin);
        input=strtoul(i,NULL,2);

        bitcount(input);
      

}
