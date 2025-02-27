#include <stdio.h>

/*int main()
{
	int x = 10;
	{
		int x = 20;
		printf("%d\n",x);
	}
	printf("%d\n",x);
	return 0;
}*/

/*int main() 
{ 
	int x = 5;
	int a,b,c;
	a = b = c = 5;
	printf("%d\n", ++x * ++x * ++x * ++x); 
	printf("%d\n", ++a * ++a * ++a);
	printf("%d\n", ++b * ++b);
	printf("%d\n", ++c);

	return 0; 
}*/

/*int main() 
{ 
	int x = -5; 
	printf("%u", x); 
	return 0; 
}*/

int main() 
{ 
	// the number we write outside the square bracket is the index of the array 
	int arr[5] = {1, 2, 3, 4, 5}; 
	printf("%d", 1[arr]); 
	return 0; 
}
