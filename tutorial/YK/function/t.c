#include <stdio.h>

void print(int (*a)[3])
{
	for ( int i=0;i<2;i++ )
        {
                for ( int j=0;j<3;j++ )
                {
			printf("%d\n",*(*(a + i)+ j));
                }
        }
//	printf("%p\n",*a);
//	printf("%d\n",*(*(a)+1));
}

void print1(int (*a)[2][2])
{
	for ( int i=0;i<2;i++ )
	{
		for ( int j=0;j<2;j++ )
		{
			for ( int k=0;k<2;k++ )
			{
				printf("%d\n",*(*(*(a + i)+ j)+ k));
			}
		}
	}
}


int main()
{
	int arr[2][3] = {1,2,3,4,5,6};
	print(arr);
	int (*ptr)[3] = arr;
	printf("%d	%p\n\n",*(*ptr),*ptr);

	int ar1[] = {1,2,3,4};
	int *ptr1 = ar1;
	printf("%d\n",*ptr1);
	printf("\n");
	int arr1[2][2][2] = {1,2,3,4,5,6,7,8};
	print1(arr1);
//	int (*ptr)[3] = arr;
/*
	for ( int i=0;i<2;i++ )
	{
		for ( int j=0;j<3;j++ )
		{
			printf("%d\n",*(*(ptr + i)+ j));
		}
	}
	*/
	return 0;
}


