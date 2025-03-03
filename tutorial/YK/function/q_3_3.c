/* Suppose 7 names are stored in an array of pointers names
as shown below:
char 'names[ ] = (
'Santsh',
'Amol',
'Santoh Jain',
'Kishore',
'Rahul,
'Amolkumar,
'Hemant');

Write a program to arrange these names in alphabetical order.
*/

#include <stdio.h>

int main()
{
	char *names[] = {"Santosh","Amol","Santosh Jain","Kishore","Rahul","Amolkumar","Hemant"};
	//char **ptr = names;
/*	printf("%s\n",*names);
	++*names;
	printf("%s\n",*names);
*/

	
//	char (*p)[13] = names;
	for ( int i=0;i<7;i++ )
	{
		for ( int j=0;names[i][j]!='\0';j++ ) {
	//	printf("%c\n",*(*(p + i) + j));
			printf("%c\n",names[i][j]);
		}
	}
	printf("%ld\n",sizeof(names));
	return 0;
}
