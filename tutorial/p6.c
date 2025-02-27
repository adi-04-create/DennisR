#include <stdio.h>
#include <stdint.h>

void fill_array( int ar[] );
void read_array( int ar[] );
void *min_array( int ar[] );
void *max_array( int ar[] );
void *search_array( int ar[],int n );

int main()
{
	int arr[10] = {0};

	fill_array(arr);
	read_array(arr);
	min_array(arr);
	max_array(arr);

	int num;
	printf("Enter a number : ");
        scanf("%d",&num);
	int *output = search_array(arr,num);

	if ( output )
	{
		printf("'%d' found at %ld position\n",num, output-arr);
	}
	else
	{
		printf("'%d' not found...\n",num);
	}

	
	return 0;
}

/* function to enter values to array */
void fill_array(int ar[])
{
        int index;

        for ( index = 0; index < 10; index++ )
        {
                printf("Enter '%d' element : ",index);
                scanf("%d",&ar[index]);
        }
        printf("\n");
}

/* function to read values from array */
void read_array(int ar[])
{
	printf("{%d,%d,%d,%d,%d,%d,%d,%d,%d,%d}\n",ar[0],ar[1],ar[2],ar[3],ar[4],ar[5],ar[6],ar[7],ar[8],ar[9]);
}

void *search_array( int ar[],int n )
{
	//while ( *ar )
	for ( int i=0;i<10;i++ )
	{
		if ( *ar == n )
		{
			return ar;
		}
		ar++;
	}
	return NULL;
}

void *min_array( int ar[] )
{
	int min = *ar;
	//while ( *ar )
	for ( int i=0;i<10;i++ )
	{
		if ( min > *ar )
		{
			min = *ar;
		}
		ar++;
	}
	printf("Minimum value of array is %d\n",min);
}

void *max_array( int ar1[] )
{
        int max = *ar1;
        while ( *ar1 )
        {
                if ( max < *ar1 )
                {
                        max = *ar1;
                }
                ar1++;
        }
        printf("Maximum value of array is %d\n",max);
}
