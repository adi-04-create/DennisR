#include <stdint.h>
#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

#define abs(x) ( (x) > 0 ? (x): -(x))

void itoa(uint32_t n,char s[]);
void reverse1(char s[]);

void returnval0()
{
    	uint32_t number;
    	char str[MAXLINE];

 /* number=-2345645; */

    	number = 2147483648;


    	printf("Integer %d printed as\n String:",number);

    	itoa0(number,str);

    	printf("%s",str);
	printf("\n");
    
}

void itoa0(uint32_t n,char s[])
{
    	uint32_t i,sign;

    	sign=n;

    	i = 0;

    	do
    	{
        	s[i++]= abs(n%10) + '0';

    	}
	while((n/=10)!=0);

    	if( sign < 0)
        	s[i++]='-';

    	s[i]='\0';

    	reverse10(s);
}

void reverse10(char s[])
{
    	uint32_t c,i,j;

    	for(i=0,j=strlen(s)-1;i<j;i++,j--)
        	c=s[i],s[i]=s[j],s[j]=c;
}
