#include <stdio.h>

uint32_t main()
{
	uint32_t a,i;
	uint32_t arr[8] = {0};
	printf("Enter a : ");
	scanf("%d",&a);

	/*printf("Enter b : ");
	scanf("%d",&b);
	printf("1 : and\n2 : or\n3 : xor\n4 : not\n");
	while(1)
	{
		scanf("%d",&c);
		switch(c)
		{
			case (1):
				uint32_t d = a&b;
				printf("%d\n",d);
				break;
			default:
				exit(0);
		}
	}
	if ( a & 1 )
	{
		printf("odd number\n");
	}
	else
	{
		printf("even number\n");
	}*/
	uint32_t d = a | 144;
	printf("%d\n",d);
	while(d > 0)
	{
		
		arr[i] = d % 2;
		d / 2;
		i++;
	}
	printf("%d\n",arr[i]);

	return 0;
}


