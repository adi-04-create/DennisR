#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap_int ( int *a, int *b );
float swap_float ( float *c, float *d );
void swap_generic ( void *e, void *f,size_t n );

int main()
{
	int a = 10;
	int b = 20;
	printf("values before swapping : a = %d, b = %d\n",a,b);
	swap_int( &a,&b );
	printf("values after swapping  : a = %d, b = %d\n",a,b);

	float c = 10;
	float d = 20;
	printf("values before swapping : c = %f, d = %f\n",c,d);
	swap_float( &c,&d );
	printf("values after swapping  : c = %f, d = %f\n",c,d);

	printf("\nUsing generic function...\n");

	printf("values before swapping : a = %d, b = %d\n",a,b);
	swap_generic( &a,&b,sizeof(int) );
	printf("values after swapping  : a = %d, b = %d\n",a,b);

	printf("values before swapping : c = %f, d = %f\n",c,d);
	swap_generic( &c,&d,sizeof(float) );
	printf("values after swapping  : c = %f, d = %f\n",c,d);

}

int swap_int ( int *x, int *y )
{
	int temp = *y;
	*y = *x;
	*x = temp;
}

float swap_float ( float *x, float *y )
{
	float temp = *y;
        *y = *x;
        *x = temp;
}

void swap_generic ( void *x, void *y, size_t n )
{
	void *temp = malloc(n);
	if ( !temp )
	{
		printf("Memory allocation failed..\n");
		return;
	}

	memcpy(temp, y, n);
	memcpy(y, x, n);
	memcpy(x, temp, n);
	free ( temp );
}
