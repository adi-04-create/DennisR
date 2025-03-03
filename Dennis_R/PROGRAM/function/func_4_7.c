/* Write a routine ungets(s) that will push back an entire string onto the input. Should unge * ts know about buf and bufp, or should it just use ungetch?
 *
 * AUTHOR   : Aditya Nathwani
 * CREATED  : 25 February, 2025
 */

/* required header files */
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf1[BUFSIZE];  // Buffer for ungetch
int bufp1 = 0;       // Next free position in buf1

/* getch to get a character from the buffer */
int getch1(void)
{
    	return (bufp1 > 0) ? buf1[--bufp1] : getchar();
}

/* ungetch to put the character back to the buffer */
void ungetch1(int c)
{
    	if (bufp1 >= BUFSIZE)
        	printf("ungetch: too many characters\n");
    	else
        	buf1[bufp1++] = c;
}

/* to put an entire string back */
void ungets(const char *s)
{
    	int len = strlen(s);
    	while (len > 0)
        	ungetch1(s[--len]);  // Push back characters in reverse order
}

void unget_string()
{
    	char testStr[] = "hello";
    	int c;

    	printf("Pushing \"%s\" back into input buffer...\n", testStr);
    	ungets(testStr);

    	printf("Retrieving characters: ");
    	while (bufp1 > 0) // Corrected loop condition
    	{
        	putchar(getch1());
    	}
    	printf("\n");

   
}
