/* required header files */
#include <stdio.h>

uint32_t display(uint32_t*,uint32_t);

/* start of main */
uint32_t main()
{
	uint32_t arr[] = {1,2,3,4,5,6,7,8,9,10};
	display(&arr[0],10);
	return 0;
}

uint32_t display(uint32_t *j,uint32_t n)
{
	uint32_t i = 1;
	while ( i <= n )
	{
		printf("%d\t",*j);
		/* j refers to as the address of the perticular index */
		printf("%p\n",j);
		i++;
		j++;
	}
	return 0;
}
