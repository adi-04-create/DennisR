/* required header files */
#include <stdio.h>
#include <stdint.h>
#define SIZE 100

/* decleration of stack structure */
typedef struct
{
        int item[SIZE];
        int top;
}stack;

/* prototype decleration of function */
void init(stack *);
void push(stack *, int);
int pop(stack *);

/* start of push function */
void push(stack *sp, int value)
{
        if (sp -> top == SIZE - 1)
        {
                printf("Stack overflow.\n");
                return;
        }
        sp -> top++;
        sp -> item[sp -> top] = value;
}
/* end of push function */

/* start of pop function */
int pop(stack *sp)
{
        if (sp -> top == -1)
        {
                printf("Stack Underflow.\n");
                return -1;
        }
        int value;
        value = sp -> item[sp -> top];
        sp -> top--;
        return value;
}
/* end of pop function */

/* initialisation of the stack */
void init(stack *sp)
{
        sp -> top = -1;
}
/* end of initialisation */

/* start of main function */
int main()
{
	printf("\n\tInfix to Postfix Converter\n\n");
	printf("Enter a normal expression : ");
	
	/* variable and array decleration */
	uint16_t ichar;
	uint16_t index = 0;
	uint16_t offset = 0;
	uint16_t array[20] = {0};

	/* while loop to get the expression */
	while (( ichar = getchar()) != EOF )
	{
		array[index] = ichar;
		index++;
	}

	for ( 



