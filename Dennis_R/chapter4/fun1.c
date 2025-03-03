#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVEL 100 /* maximum depth of val stack */
#define BUFSIZE 100

uint32_t getop(char[]);
char buf[BUFSIZE]; /* buffer for ungetch */
uint32_t bufp = 0; /* next free position in buf */
uint32_t sp = 0;   /* next free stack position */
double val[MAXVEL]; /* value stack */
uint32_t stack[10] = {0};
uint32_t index;
uint32_t getch(void);
void ungetch(uint32_t);
int push(double);
int is_empty();
int pop();
double peek(void);
void print_stack(void);

int is_empty()
{
    return sp == 0;  // Returns 1 if empty, 0 otherwise
}

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
            stack[index] = push(pop() + pop());
	    printf("%f\n",stack[index]);
		index++;
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));  // Corrected modulo operation
            else
                printf("error: zero divisor in modulo\n");
            break;
        case 't':  // 't' for top
            if (!is_empty())  // Check if stack is not empty
                printf("Top of stack: %.8g\n", peek());
            else
                printf("error: stack is empty\n");
            break;
        case 'p':  // 'p' for print stack
            print_stack();
            break;
        case '\n':
            printf("\t%d\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}

/* peek: Return the top element without popping */
double peek(void)
{
    if (sp > 0)  // Stack pointer > 0 means stack is not empty
        return val[sp - 1];  // Return the top element
    else
    {
        printf("error: stack is empty\n");
        return 0.0;  // Default return value
    }
}

/* print_stack: Print all elements in the stack */
void print_stack(void)
{
    if (sp == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Current Stack:\n");
    for (int i = sp - 1; i >= 0; i--)  // Print from top to bottom
        printf("%.8g\n", val[i]);
}

/* push: push f onto value stack */
int push(double f)
{
    if (sp < MAXVEL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    return 0;
}

/* pop: pop and return top value from stack */
int pop()
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
    return 0;
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

