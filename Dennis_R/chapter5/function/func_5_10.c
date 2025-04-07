/* Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument.
 *
 * Author   : Aditya Nathwani
 * Created  : 15 March, 2025
 */

#include <stdio.h>
#include <stdlib.h>  // For atof(), exit()
#include <ctype.h>   // For isdigit()

#define MAXSTACK 100  // Stack size

// Stack implementation
double stack[MAXSTACK];
int sp = 0;  // Stack pointer

void push(double val) 
{
	if (sp < MAXSTACK) 
	{
		stack[sp++] = val;
	} 
	else 
	{
		printf("Error: Stack full\n");
		exit(1);
	}
}

double pop() 
{
	if (sp > 0) 
	{
		return stack[--sp];
	} 
	else 
	{
		printf("Error: Stack empty\n");
		exit(1);
	}
}

int main(int argc, char *argv[]) 
{
	if (argc < 2) 
	{
		printf("Usage: expr <RPN expression>\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
       	{
		if (isdigit(argv[i][0]) || (argv[i][0] == '-' && isdigit(argv[i][1]))) 
		{
			// If it's a number, push onto the stack
			push(atof(argv[i]));
		} 
		else if (argv[i][1] == '\0') 
		{  // Single-character operators
			double op2;
			switch (argv[i][0]) 
			{
				case '+': 
					push(pop() + pop()); 
					break;
				case '-': 
					op2 = pop(); push(pop() - op2); 
					break;
				case '*': 
					push(pop() * pop()); 
					break;
				case '/': 
					op2 = pop();
					if (op2 != 0.0)
						push(pop() / op2);
					else 
					{
						printf("Error: Division by zero\n");
						return 1;
					}
					break;
				default:
					printf("Error: Unknown operator %s\n", argv[i]);
					return 1;
			}
		} 
		else 
		{
			printf("Error: Invalid input %s\n", argv[i]);
			return 1;
		}
	}

	if (sp == 1) {
		printf("Result: %.2f\n", pop());
	} else {
		printf("Error: Malformed expression\n");
		return 1;
	}

	return 0;
}
