#include <stdio.h>

int main()
{
	int index = 0;
	char ichar;
	int arr[50] = {0};

	while (( ichar = getchar()) != EOF && ichar != '\n' )
	{
		arr[index++] = ichar;
	}

	for ( int i=0;i<50;i++ )
	{
		if ( arr[i] == '\t' )
		{
			printf("    ");
		}
		else
			printf("%c",arr[i]);
	}
	printf("\n");
}
