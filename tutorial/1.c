#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* int a[plain][row][column] */
	int a[3][3][3] ={	10,20,30,
				40,50,60,
				70,80,90,
				90,80,70,
				60,50,40,
				30,20,10,
				30,20,10,
				60,50,40,
				90,80,70	};

	int b[1][2][3] ={	1,2,3,
				4,5,6	};
	
	int (*ptr)[2][3] = b;
	int (*p)[3][3] = a;

	printf("%p\n",*p);
	printf("%p\n",*(*p));
	printf("%d\n",*( *( *( p +1) +2) +2) );

	printf("%d\n",*( *( *( ptr ) +1) ));

//	int *ptr = (int *)malloc(10 * sizeof(int));

//	printf("%d\n",*ptr);
	return 0;
}
