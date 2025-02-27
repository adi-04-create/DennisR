/* required header files */
#include<stdio.h>
#define MAXLINE 1000

/* start of function */
void escape(char s[],char t[])
{
	/* variable decleration */	
    	int index1,index2;
	/* variable initialisation */
    	index1=index2=0;
	
	/* start of while loop */
    	while(t[index1] != '\0')
    	{
		/* start of switch cases */
        	switch(t[index1])
        	{
            		case '\t':
                    		s[index2]='\\';
                    		++index2;
                    		s[index2]='t';
                    		break;
            		case '\n':
                    		s[index2]='\\';
                    		++index2;
                    		s[index2]='n';
                    		break;
	    		case ' ':
		    		s[index2]='\\';
		    		++index2;
		    		s[index2]='s';
		    		break;
            		default:
                    		s[index2]=t[index1];
                    		break;
        	}
		/* increasing the index of input and output string */
        	++index1;
        	++index2;
    	}

	/* terminating null character */
   	s[index2]='\0';
}
/* end of function */

/* start of getline function */
int mgetline(char s[],int lim)
{
	/* variable decleration */
    	int i,c;

	/* for loop for storing the value to array */
    	for(i=0;i<lim-1 && (c=getchar())!=EOF;++i)
        	s[i]=c;
  

    	s[i]='\0';
 
}
/* end of getline function */

/* start of function */
void char_catch()
{
	printf("\tconverts characters like newline and tab into visible escape sequences like \\n and \\t\n\n");
    	char s[MAXLINE],t[MAXLINE];

	/* calling of mgetline function */
    	mgetline(t,MAXLINE);

	/* calling of escape function */
    	escape(s,t);

    	printf("%s",s);
    	printf("\n");

}
/* end of function */
