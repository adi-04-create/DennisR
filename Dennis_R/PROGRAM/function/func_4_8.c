#include <stdio.h>

/* holds the single pushback character, -1 means empty */
int buf = -1;

/* modified getch function */
int getch2(void)
{
	/* check if there is a pushback character */
    	if (buf != -1)
    	{
        	int temp = buf;
        	/* clear the pushback buffer */
		buf = -1;
        	return temp;
    	}
    	return getchar();
}

/* modified ungetch */
void ungetch2(int c)
{
	/* only 1 character can be pushed back */
    	if (buf != -1)
        	printf("ungetch: already holding a character\n");
    	else
        	buf = c;  // Store the character for future retrieval
}

void modified_version()
{
    	int c;

    	printf("Enter a character: ");
	char buffer = getchar();
    	c = getchar();
    	ungetch2(c);  // Push it back
    	ungetch2(c);  // Push it back


    	printf("Retrieving character: %c\n", getch2());  // Should print the same character
}

