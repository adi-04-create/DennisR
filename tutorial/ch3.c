#include <stdio.h>
#include <string.h>
/*int main()
{
	char string[] = "oddLengthString";
	char *ptr1 = string;
	char *ptr2 = string + sizeof (string) - 2;
	printf("%c\n",*ptr1);
	printf("%c\n",*ptr2);
	int i;
	for( i=0; ptr1 != ptr2; i++ )
	{
		++ptr1;
		--ptr2;
	}

	printf("%d\n",i);

	return 0;
}
*/



/*int main()
{
	static char str1[] = "Good";
	static char str2[20];
	static char str3[20] = "Day";
	int i;

	i = strcmp ( strcat ( str3,strcpy( str2,str1 ) ),strcat ( str3,"good" ) );
	char *op = strcat ( str3,strcpy( str2,str1 ) );
	printf("%s\n",op);
	printf("%d\n",i);

	return 0;
}*/



/*int main()
{
	char str[] = "Hello I am Aditya Nathwani";

	for ( int i=0; i<=5; i++ )
		printf("%c",*(str + i));
	printf("\n");

	for ( int i=0; i<=1; i++ )
		printf("%c",*(str + 6 + i));
	printf("\n");

	for ( int i=0; i<=2; i++ )
		printf("%c",*(str + 8 + i));
	printf("\n");

	for ( int i=0; i<=6; i++ )
		printf("%c",*(str + 11 + i));
	printf("\n");

	for ( int i=0; i<=8; i++ )
		printf("%c",*(str + 18 + i));
	printf("\n");
	return 0;
}*/



int main()
{
	char s[] = "my is nathwani ";
	char t[] = "name aditya ";
	char u[40];
	char *ss = s,*tt = t,*uu = u;
	while ( *ss || *tt )
	{
		while ( *ss )
		{
			if ( ( *uu++ = *ss++ ) == ' ')
				break;
		}
		while ( *tt )
		{
			if ( ( *uu++ = *tt++ ) == ' ')
				break;
		}
	}
	*uu = '\0';
	puts(u);
}




