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
	printf("%s\n",*names);
	*names+=55;
	printf("%s\n",*names);

	//printf("%s\n",*ptr);
	printf("%ld\n",sizeof(names));
	return 0;
}
