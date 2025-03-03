#include <stdint.h>
#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

#define abs(x) ( (x) > 0 ? (x): -(x))

void itoa1(long int n,char s[]);
void reverse2(char s[]);

void returnval1()
{
    	long int number;
    	char str[MAXLINE];

 /* number=-2345645; */

    	number = 210000000000;


    	printf("Integer %ld printed as String :",number);

    	itoa1(number,str);

    	printf("%s",str);
	printf("\n");
    
}

void itoa1(long int n,char s[])
{
    	long int i,sign;

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

    	reverse2(s);
}

void reverse2(char s[])
{
    	long int c,i,j;

    	for(i=0,j=strlen(s)-1;i<j;i++,j--)
        	c=s[i],s[i]=s[j],s[j]=c;
}
