/* This is the central program for question number 3,4 and 5 because all the modifications have been performed over here
 *
 * Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.
 *
 * Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 *
 * Add access to library functions like sin, exp, and pow.
 */

/*
 * AUTHOR   : ADITYA NATHWANI
 * CREATED  : 5 FEBRUARY, 2025
 * MODIFIED : 25 FEBRUARY, 2025
 */

/* required header files */
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/* variable decleration */
#define MAXOP 100 		/* max size of operand or operator */
#define NUMBER '0' 		/* signal that a number was found */
#define MAXVEL 100 		/* maximum depth of val stack */
#define BUFSIZE 100

char buf1[BUFSIZE]; 		/* buffer for ungetch */
int bufp1 = 0; 			/* next free position in buf */
int sp1 = 0; 			/* next free stack position */
double val1[MAXVEL]; 		/* value stack */

/* prototype function decleration */
int getch1(void);
void ungetch1(int);
void push1(double);
double pop1(void);
void top1(void);
void dup1(void);
void swap1(void);
void clear1(void);
int getop1(char s[]);

/* reverse Polish calculator */
void stack_operation2()
{
    	int type;
    	double op1, op2;
    	char s[MAXOP];

	/* start of while loop */
    	while ((type = getop1(s)) != EOF)
    	{
		/* start of switch cases */
        	switch (type)
        	{
            		case NUMBER:
                		push1(atof(s));
                		break;
            		case '+': /* addition */
                		push1(pop1() + pop1());
                		break;
            		case '*': /* multiplication */
                		push1(pop1() * pop1());
                		break;
            		case '-': /* subtraction */
                		op2 = pop1();
                		op1 = pop1();
                		push1(op1 - op2);
                		break;
            		case '/': /* division */
                		op2 = pop1();
                		if (op2 != 0.0)
                    			push1(pop1() / op2);
                		else
                    			printf("error: zero divisor\n");
                		break;
			case '%': /* modulo operator */
                		op2 = pop1();
                		op1 = pop1();
                		if (op2 != 0.0)
                    			push1(fmod(op1, op2));
                		else
                    			printf("error: zero divisor in modulo\n");
                		break;
            		case 't': /* Print top element */
                		top1();
                		break;
            		case 'd': /* Duplicate top element */
                		dup1();
                		break;
            		case 'S': /* Swap top two elements */
                		swap1();
                		break;
			case 's':  // sin(x)
                		push1(sin(pop1()));
                		break;
            		case 'e':  // exp(x)
                		push1(exp(pop1()));
                		break;
            		case 'p':  // pow(x, y)
                		op2 = pop1();
                		op1 = pop1();
                		push1(pow(op1, op2));
                		break;
            		case 'c': /* Clear stack */
                		clear1();
                		break;
	    		case '\n': /* if we encounter a newline */
    				if (sp1 > 0)
        				printf("\t%.8g\n", val1[sp1 - 1]); // Print top without popping
    				else
        				printf("error: stack empty\n");
    				break;
			case 'q': /* to exit the program */
				printf("Exiting...\n");
				return;
            		default:
                		printf("error: unknown command %s\n", s);
                		break;
        	}
		/* end of switch cases */
    	}
	/* end of while loop */
}
/* end of stack operation function */

/* push: push f onto value stack */
void push1(double f)
{
    	if (sp1 < MAXVEL)
        	val1[sp1++] = f;
    	else
        	printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop1(void)
{
    	if (sp1 > 0)
        	return val1[--sp1];
    	else
    	{
        	printf("error: stack empty\n");
        	return 0.0;
    	}
}

/* top: print top element without popping */
void top1(void)
{
    	if (sp1 > 0)
        	printf("Top element: %.8g\n", val1[sp1 - 1]);
    	else
        	printf("error: stack empty\n");
}

/* dup: duplicate top element */
void dup1(void)
{
    	if (sp1 > 0)
    	{
        	if (sp1 < MAXVEL)
            		push1(val1[sp1 - 1]);
        	else
            	printf("error: stack full, can't duplicate\n");
    	}
    	else
        	printf("error: stack empty\n");
}

/* swap: swap the top two elements */
void swap1(void)
{
    	if (sp1 > 1)  // Ensure there are at least 2 elements
    	{
        	double temp = val1[sp1 - 1];
        	val1[sp1 - 1] = val1[sp1 - 2];
        	val1[sp1 - 2] = temp;
    	}
    	else
        	printf("error: not enough elements to swap\n");
}

/* clear: clear the stack */
void clear1(void)
{
    	sp1 = 0;
    	printf("Stack cleared\n");
}

/* getop: get next character or numeric operand */
int getop1(char s[])
{
    	int i, c;
    	while ((s[0] = c = getch1()) == ' ' || c == '\t')
        ;

    	s[1] = '\0';
    	if (!isdigit(c) && c != '.')
        	return c;

    	i = 0;
    	if (isdigit(c))
        	while (isdigit(s[++i] = c = getch1()))
            	;

    	if (c == '.')
        	while (isdigit(s[++i] = c = getch1()))
            	;

    	s[i] = '\0';
    	if (c != EOF)
        	ungetch1(c);

    	return NUMBER;
}

/* getch: to get the characters into the buffer */
int getch1(void) 
{ 
	return (bufp1 > 0) ? buf1[--bufp1] : getchar(); 
}

/* ungetch: to take the characters from the buffer */
void ungetch1(int c) 
{ 
	if (bufp1 >= BUFSIZE) printf("ungetch: too many characters\n"); else buf1[bufp1++] = c; 
}

/* start of main function */
int main()
{
	stack_operation2();
	return 0;
}
