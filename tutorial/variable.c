#include <stdio.h>

uint32_t count(uint32_t a)
{
	//uint32_t count;
	a++;
	printf("%d\n",a);
	return 0;
}
uint32_t main()
{
	uint32_t a;
	count(a);
	count(a);
	count(a);
	return 0;
}
