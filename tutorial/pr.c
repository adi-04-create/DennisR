#include <stdio.h>

int main()
{
	char i=10;
	char j=15;
	int diff;

	diff = &i - &i;

	printf("&i = %p\t&j = %p\n",&i,&j);
	printf("diff = %d\n",diff);

	int a = 10;
	int *ptr = &a;
	printf("a = %d\t&a = %p\n",*ptr,ptr);
	*ptr = 1000;
	printf("%p\n%d\n",ptr,*ptr);
	return 0;
}
