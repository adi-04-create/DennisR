#include <stdio.h>
#include <stdlib.h>

typedef struct User
{
	uint32_t id;
	uint32_t sal;
}user;

void main()
{
	user *ptr = NULL;
	uint32_t count = 10;

	ptr = (user *)calloc(10, sizeof(user));

	if(ptr == NULL)
	{
		printf("Memory Allocation Failed...\n");
		exit(-1);
	}

	printf("Memory Allocation Successful...\n");
	for(count = 0;count < 10;count++)
	{
		ptr[count].id = count;
		ptr[count].sal = count + 100;
	}

	for(count = 0;count < 10;count ++)
	{
		printf("\nuser [%d] id = (%d)",count,ptr[count].id);
		printf("\tuser [%d] salary = (%d)",count,ptr[count].sal);
	}
	printf("\n");
	free(ptr);
	for(count = 0;count < 10;count ++)
        {
                printf("\nuser [%d] id = (%d)",count,ptr[count].id);
                printf("\tuser [%d] salary = (%d)",count,ptr[count].sal);
        }
        printf("\n");
}

