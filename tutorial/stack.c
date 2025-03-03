#include <stdio.h>
#define SIZE 100

typedef struct
{
	int item[SIZE];
	int top;
}stack;

void init(stack *);
void push(stack *, int);
int pop(stack *);

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

void init(stack *sp)
{
	sp -> top = -1;
}

int main()
{
	stack s1,s2;
	init(&s1);
	init(&s2);
	/*push(&s1, 100);
	push(&s1, 200);
	push(&s2, 10);
	push(&s2, 20);
	printf("From stack 1 : %d\tFrom stack 2 : %d\n",pop(&s1),pop(&s2));
	*/
	/* A + B * C --- A B C * + */
/*	int arr[20] = {0};
	int array[20] = {0};
	int j = 0;
	int ichar;
	int index = 0;
	printf("Enter an expression : ");
	while ((ichar = getchar()) != EOF && ichar != '\n')
	{
		arr[index] = ichar;
		index++;
	}
	for( int i=0;i<index;i++ )
        {
		if ( arr[i] != ' ' )
		{
			array[j] = arr[i];
                }
        }
	printf("\n%ls\n",array);*/

	printf("Enter an Expression : ");


	return 0;

	
}

