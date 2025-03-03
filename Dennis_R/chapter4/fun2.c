#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100 /* buffer size */
#define VAR_COUNT 26 /* 26 single-letter variables */

int sp = 0;            /* next free stack position */
double val[MAXVAL];    /* value stack */
double vars[VAR_COUNT]; /* 26 single-letter variables */
double last_printed;   /* last printed value */
char buf[BUFSIZE];     /* buffer for ungetch */
int bufp = 0;          /* next free position in buf */

void push(double f);
double pop(void);
void print_top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);
int getop(char []);
int getch(void);
void ungetch(int);
void ungets(char *s);
void itoa(int n, char s[]);
void reverse(char s[]);

/* Push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* Pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* Print top element without popping */
void print_top(void) {
    if (sp > 0)
        printf("Top of stack: %.8g\n", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* Duplicate the top element */
void duplicate_top(void) {
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* Swap the top two elements */
void swap_top(void) {
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else {
        printf("error: not enough elements to swap\n");
    }
}

/* Clear the stack */
void clear_stack(void) {
    sp = 0;
}

/* Get next operator or numeric operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (c == '-') { /* handle negative numbers */
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
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

/* Get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* Push back an entire string onto input */
void ungets(char *s) {
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

/* Reverse Polish Calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor in modulo\n");
                break;
            case 't':
                print_top();
                break;
            case 'd':
                duplicate_top();
                break;
            case 's':
                swap_top();
                break;
            case 'c':
                clear_stack();
                break;
            case '\n':
                last_printed = pop();
                printf("\t%.8g\n", last_printed);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

