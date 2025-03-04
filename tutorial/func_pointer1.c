#include <stdio.h>
#include <string.h>

int main()
{
	char string1[] = "Hello";
	printf("%s\n",string1);

	char *ptr = string1;
	/*printf("%c\n",*ptr);*/

	/**ptr = 'M';
	printf("%c\n",*ptr);
	printf("%s\n",string1);*/

	int i;
	printf("Enter an Index : ");
	scanf("%d",&i);
	if ( i >= strlen(string1) )
	{
		printf("Invalid Index...\n");
		return 0;
	}
	*(ptr + i) = 'M';
	printf("%s\n",string1);
	return 0;


}
