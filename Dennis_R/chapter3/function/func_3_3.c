
/* REQUIRED HEADER FILES */
#include <stdio.h>
#define MAXLINE 100

/* START OF FUNCTION */
uint32_t mgetline2(char s[],uint32_t lim)
{
	printf("\tExpands the given input in the form a-z.\n\n");
    	/* VARIABLE DECLERATION */	
    	uint32_t index,ichar;
    
    	/* GETTING CHARACTERS TILL EOF AND NEWLINE */
    	for( index=0; index<lim-1 && (ichar=getchar()) != EOF && ichar != '\n'; ++index )
        	s[index]=ichar;

    	if( ichar == '\n' )
        	s[index++]=ichar;

    	s[index]='\0';
}
/* end of getline function */

/* start of expand function */
void expand(char s1[],char s2[])
{
    	uint32_t i,j,c;

    	i=j=0;

    	while( (c=s1[i++]) != '\0' )
	{
        	if( s1[i] == '-' && s1[i+1] >= 'c' )
        	{
            		i++;
            		while(c < s1[i])
            			s2[j++]=c++;
        	}
        	else
            		s2[j++]=c;
		if( s1[i] == '-' && s1[i+1] <= 'c' )
		{
			i++;
			while(c>s1[i])
				s2[j++]=c--;
		}
		else
			s2[j++]=c;
	}

    		s2[j]='\0';
}
/* end of expand function */

void expansion()
{
    	char s1[MAXLINE],s2[MAXLINE];
    	mgetline2(s1,MAXLINE);
    	expand(s1,s2);
    	printf("%s",s2);
}
