#include <stdio.h>

uint32_t main()
{
	/* declaring a pointer to character */
	char *address1;
	/* declaring a variable */
	char data = 100;
	/* storing the address of data into address1 variable */	
	address1 = &data;
	/* printing the value which is present at the address stored inside the address1 variable */
	printf ("%d\n",*address1);
	/* printing the address present inside the variable address1 */
	printf ("%p\n",address1);
	return 0;
}
