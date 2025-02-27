#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

// Function prototypes
int getop(char []);
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
double peek();  // ✅ Added function prototype
int is_empty();

int is_empty()
{
    return sp == 0;  // Returns 1 if empty, 0 otherwise
}

/* reverse Polish calculator */
void stack_operation()
{
    int type;
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2)); 
            else
                printf("error: zero divisor in modulo\n");
            break;
        case 't':  // 't' for top
    		if (!is_empty())  // Check if stack is not empty
    		{
        		double top_value = peek();
        		printf("Top of stack: %.8g\n", top_value);
    		}
    		else
        		printf("error: stack is empty\n");
    		break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}

/* peek: return the top element without popping */
double peek()
{
    if (sp > 0)
        return val[sp - 1]; 
    else
    {
        printf("error: stack is empty\n");
        return 0.0; 
    }
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
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
int getop(char s[])
{
    int i, c;
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

int getch(void)  /* get a (possibly pushed-back) character */
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

