#include <stdio.h> 
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h> /* for atof() */ 
#define MAXOP 100 /* max size of operand or operator */ 
#define NUMBER '0' /* signal that a number was found */ 
#define MAXVEL 100 /* maximum depth of val stack */
#define BUFSIZE 100
uint32_t getop(char []);
char buf[BUFSIZE]; /* buffer for ungetch */
uint32_t bufp = 0; /* next free position in buf */
uint32_t sp = 0; /* next free stack position */
double val[MAXVEL]; /* value stack */
uint32_t getch(void);
void ungetch(uint32_t);
void pu7sh(double); 
double pop(void); 
/* reverse Polish calculator */ 
void stack_operation() 
{ 
	uint32_t type; 
	double op2; 
	char s[MAXOP]; 
	while ((type = getop(s)) != EOF)
	{ 
		switch (type)
		{ 
		case NUMBER: 
			push(atof(s)); 
			break; 
		case '+': 
			push(pop() + pop()); 
			break; 
		case '*': 
			push(pop() * pop()); 
			break; 
		case '-': 
			op2 = pop(); 
			push(pop() - op2); 
			break; 
		case '/': 
			op2 = pop(); 
			if (op2 != 0.0) 
				push(pop() / op2); 
			else 
				printf("error: zero divisor\n"); 
			break; 
		case '\n': 
			printf("\t%.8g\n", pop()); 
			break;
/*		case '%':
            		op2 = pop();
            		if (op2 != 0.0)
                		push((pop()%op2));  // Corrected modulo operation
            		else
                		printf("error: zero divisor in modulo\n");
            		break;	*/
		default: 
			printf("error: unknown command %s\n", s); 
			break; 
		} 
	}
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVEL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next character or numeric operand */
uint32_t getop(char s[])
{
	uint32_t i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
	;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
		;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
		;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

uint32_t getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(uint32_t c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
