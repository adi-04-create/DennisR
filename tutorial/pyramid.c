#include <stdio.h>

uint32_t main()
{
	uint32_t num;
	printf("Enter the size of pyramid : ");
	scanf("%d",&num);

	for(uint32_t i=1;i<=num;i++)
	{
		for(uint32_t j=i;j>0;j--)
		{
			printf("%d\t",j);
		}
		printf("\n");
	}
	for(uint32_t i=1;i<=num;i++)
	{
		for(uint32_t j=num-1;j>0;j--)
		{
			printf("\t");
			for(uint32_t k=i;k>0;k--)
			{
				printf("%d",k);
			}
		}
		printf("\n");
	}
	return 0;
}
