/* required header files */
#include <stdio.h>

/* start of main */
uint32_t main()
{
	/* variable decleration */
	uint32_t i = 3;
	/* value at address contained in j is an integer */
	uint32_t *j;
	/* k is a pointer to a pointer */
	uint32_t **k;
	/* j contains the address of i */
	j = &i;
	/* k contains the address of j */
	k = &j;
	printf("i = :%d\n",i);
	/* print address of i */
	printf("address of i = :%p\n",&i);
	/* value at the address of i */
	printf("i = :%d\n",*(&i));
	printf("j = :%p\n",j);
	printf("address of j = :%p\n",&j);
	/* value at the address of j */
	printf("j = :%p\n",*(&j));
	printf("k = :%p\n",k);
	printf("i = :%d\n",**k);
	printf("k = :%p\n",*(&k));
	printf("address of k = :%p\n",&k);
	return 0;
}
