#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

#define BUFSIZE 100
char buf[BUFSIZE]; 					/* buffer for ungetch */
int bufp = 0; 						/* next free position in buf */

int getch(void) 					/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 					/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign, next;

	while (isspace(c = getch()))  			/* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);  				/* it is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		next = getch();
		if (!isdigit(next)) {  
			/* Push both characters back if next isn't a digit */
			ungetch(next);
			ungetch(c);
			return 0;
		}
		c = next; /* Continue with digit */
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}
int main()
{
	int num;
	printf("Enter a number: ");

	if (getint(&num))  // Check if getint successfully retrieved an integer
		printf("You entered: %d\n", num);
	else
		printf("Invalid input!\n");

	return 0;
}

