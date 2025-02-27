#include <stdio.h>
#include <stdlib.h>

void main()
{
	uint32_t *ptr = NULL;
	uint32_t count = 10;

	ptr = (uint32_t *)malloc(10 * sizeof(uint32_t));

	if (ptr == NULL)
	{
		printf("Memory Allocation failed...\n");
		exit(-1);
	}
	else
		printf("Memory Allocated Successfully...\n");
	for(count = 0;count < 10;count++)
	{
		ptr[count] = count;
	}

	for(count = 0;count < 10;count++)
	{
		printf("\nptr[%d] = (%d)",count,ptr[count]);
	}
	printf("\n");
	
	free(ptr);

	/*ptr = (uint32_t *)malloc(10 * sizeof(uint32_t));
        if (ptr == NULL)
        {
                printf("Memory Allocation failed...\n");
                exit(-1);
        }
        else
                printf("Memory Allocated Successfully...\n");
	for(count = 1;count < 11;count++)
        {
                ptr[count] = count;
        }*/
	for(count = 1;count < 11;count++)
        {
                printf("\nptr[%d] = (%d)",count,ptr[count]);
        }
        printf("\n");

}
