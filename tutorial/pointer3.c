#include <stdio.h>

uint32_t main()
{
	uint32_t i = 10000000,*j;
	float a = 3.1415,*k;
	void *p1,*p2;

	p1 = (char*)&i;
	p2 = (char*)&a;
	
	p1 = &i;
	p2 = &a;

	j = p1;
	k = p2;

	printf("i = %d\n",i);
	printf("a = %f\n",a);
	printf("address of i = %p\n",&i);
	printf("address of a = %p\n",&a);
	printf("i = %d\n",*p1);
	printf("a = %f\n",*p2);
	printf("%f\n",*j);
	printf("%f\n",*k);
}
