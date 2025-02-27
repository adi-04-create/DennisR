#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
	int x;
	int y;
	void fill_structure();
	void read_structure();
}Point;

Point pointsarray[5];
int i;

Point fill_structure();
Point read_structure();

int main()
{
//	Point pointsarray[5];
//	int i;

	/* dynamic allocation */
//	Point *ptr = (Point*)malloc(5 * sizeof(Point));

//	if ( ptr == NULL )
//	{
//		printf("Memory allocation failed..\n");
//	}

/*	for ( i=0; i<5; i++ )
	{
		printf("Enter x coordinate at #%d position : ", i+1);
		scanf("%d",&ptr[i].x);
		printf("Enter y coordinate at #%d position : ", i+1);
		scanf("%d",&ptr[i].y);
	}

	for ( i=0; i<5; i++ )
	{
		printf("The coordinates at #%d are (%d,%d)\n",i+1,ptr[i].x,ptr[i].y);
	}*/

	fill_structure();
	read_structure();

//	free(ptr);
	return 0;
}

Point fill_structure()
{
	Point *ptr = (Point*)malloc(5 * sizeof(Point));
        for ( i=0; i<5; i++ )
        {
                printf("Enter x coordinate at #%d position : ", i+1);
                scanf("%d",&ptr[i].x);
                printf("Enter y coordinate at #%d position : ", i+1);
                scanf("%d",&ptr[i].y);
        }
}

Point read_structure()
{
	for ( i=0; i<5; i++ )
        {
                printf("The coordinates at #%d are (%d,%d)\n",i+1,ptr[i].x,ptr[i].y);
        }
}



