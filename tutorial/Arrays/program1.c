/* required header files */
#include <stdio.h>

/* start of main */
uint32_t main()
{
	/* array, integer and pointer decleration and initialisation */
	uint32_t arr[] = {1,2,3,4,5,6};
	uint32_t i = 0,*j;

	/* pointer to point at the first location of array */
	j = &arr[0];

	/* while loop for whole length of array */
	while(i <= 5)
	{
		printf("%d\t",arr[i]);
		printf("%p\t",&arr[i]);
		printf("%d\n",*j);

		/* increamenting the value of j, it points to the next memory location of its 		        type */
		j++;
		i++;
	}
	return 0;
}
