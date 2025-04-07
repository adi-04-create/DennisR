#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

//#include <stdio.h>
//#include <ctype.h>

//int getch(void);
//void ungetch(int);

/* getfloat: get next floating-point number from input into *pf */
int getfloat(float *pf)
{
	int c, sign, next;
	float power;

	while (isspace(c = getch()))  /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);  /* it is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		next = getch();
		if (!isdigit(next) && next != '.') {
			/* Push both characters back if next isn't a digit or decimal */
			ungetch(next);
			ungetch(c);
			return 0;
		}
		c = next; /* Continue with digit or decimal point */
	}

	for (*pf = 0.0; isdigit(c); c = getch())  /* integer part */
		*pf = 10.0 * *pf + (c - '0');

	if (c == '.') {  /* handle decimal point */
		c = getch();
		for (power = 1.0; isdigit(c); c = getch()) {
			*pf = 10.0 * *pf + (c - '0');
			power *= 10.0;
		}
		*pf /= power;
	}

	*pf *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

int main()
{
	float num;
	printf("Enter a floating-point number: ");

	if (getfloat(&num))  // Check if getfloat successfully retrieved a number
		printf("You entered: %f\n", num);
	else
		printf("Invalid input!\n");

	return 0;
}

