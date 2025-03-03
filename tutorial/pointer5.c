/* function returning pointers */
#include <stdio.h>
uint32_t main()
{
	uint32_t *p;
	uint32_t *fun();
	p = fun();
	printf("%p\n",p);
	printf("%d\n",*p);
	return 0;
}

uint32_t *fun()
{
	static uint32_t i = 20;
	return ( &i );
}
