#include <stdio.h>

int main()
{
	const int a = 10;
	int b = 20;
	const int c = 30;
	const d = 'c';

	/* pointer to a variable */
	int *pt = &b;
	
	/* pointer to a constant variable */
	int const *ptr = &a;

	/* constant pointer to a variable */
	int *const ptr1 = &b;
	
	/* constant pointer to a constant integer */
	const int *const ptr2 = &c;


	//a = 20;
	//ptr1 = &a;
	//ptr2 = &b;
	//c = 40;
	
	printf("a = %d\t\taddress = %p\n",*ptr,ptr);
	printf("b = %d\t\taddress = %p\n",*ptr1,ptr1);
	printf("b = %d\t\taddress = %p\n",*pt,pt);
	printf("c = %d\t\taddress = %p\n",*ptr2,ptr2);
	printf("Size of constant : %lu\n",sizeof(d));

	return 0;
}
