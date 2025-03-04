#include <stdio.h>

/*void eventA()
{
	printf("event A handled.\n");
}
void eventB()
{
	printf("event B handled.\n");
}

void( *ptr )( void );
*/
int add ( int a,int b )
{
	return a+b;
}
int sub ( int a,int b )
{
	return a-b;
}
int mul ( int a,int b )
{
	return a*b;
}
int div ( int a,int b )
{
	return a/b;
}

//int( *p1 )( int,int );

int myprogram(int (*func)(),int x,int y)
{
	int result = func(x,y);
	printf("Result : %d\n",result);
}

int main()
{
	int( *p1[4] )( int,int ) = {add,sub,mul,div};
	myprogram(p1[0],5,5);
	myprogram(p1[1],5,5);
	myprogram(p1[2],5,5);
	myprogram(p1[3],5,5);

/*	ptr = eventA;
	ptr();
	ptr = eventB;
	ptr();

	int x=10;
	int y=20;
	p1 = add;
	printf("%d\n",p1(x,y));
*/
	return 0;
}
