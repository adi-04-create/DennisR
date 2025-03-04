#include <stdio.h>

#if PRINTF_ENABLE == 0
    #define printf(...)  // Disable printf
#endif

void eventA()
{
	printf("Event A handled.\n");
}
void eventB()
{
	printf("Event B handled.\n");
}


/* pointer to function which carries the address of function */
/* which returns void and has no arguments */
void ( *eventhandler )();


/* decleration of function */
void addition()
{
	int a = 10;
	int b = 20;
	int c;
	c = a+b;
	printf("c = %d\n",c);
}

/* creating a pointer to function which returns an int and gives nothing as arguments */
void ( *ptr )();

/* decleration of functions */
int add ( int a, int b )
{
	return a + b;
}
int sub ( int a, int b )
{
	return a - b;
}

int mul ( int a, int b )
{
	return a * b;
}

int div ( int a, int b )
{
	return a / b;
}

/* decleration of function */
/* where we are passing a function and 2 integers as arguments */
void performoperation ( int (*func)(),int x,int y)
{
	int result = func(x,y);
	printf("Result : %d\n",result);
}

int main()
{
	/* pointer to function which has 2 arguments */
	int (*operation[4])(int,int) = {add,sub,mul,div};

	/* passing the function pointer and arguments */
	/* as an argument to another function */
	/* and in here we are passing the pointer to function
	 * and 2 integers as arguments */
	performoperation(operation[0],5,3);
	performoperation(operation[1],5,3);
	performoperation(operation[2],5,3);
	performoperation(operation[3],5,3);

	/* pointer carries the address of eventA function */
	eventhandler = eventA;

	/* calling the pointer to function */
	eventhandler();

	eventhandler = eventB;
	eventhandler();

	/* now, this pointer carries the address of function addition */
	ptr = addition;

	/* calling the pointer to function */
	ptr();
}

