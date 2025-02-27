/* required header files */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* decleration of structure for points */
typedef struct 
{
    	float x;
    	float y;
}Point;

/* decleration of structure for lines */
typedef struct
{
	Point lines;
}Line;

/* prototype decleration of function */
void fill_structure(Point *ptr, int size);
void read_structure(Point *ptr, int size);
void line_length(Point *ptr);

/* start of main function */
int main() 
{
    	int n = 5;

    	/* Dynamic allocation */
    	Point *pointsArray = (Point *)malloc(n * sizeof(Point));

    	if (pointsArray == NULL) 
	{
        	printf("Memory allocation failed..\n");
        	return 1;
    	}

    	/* Fill and read structures */
    	fill_structure(pointsArray, n);
    	read_structure(pointsArray, n);
	line_length(pointsArray);

    	/* Free allocated memory */
    	free(pointsArray);
    	return 0;
}
/* end of main function */

/* start of fill_structure function */
void fill_structure(Point *ptr, int size) 
{
    	for (int i = 0; i < size; i++) 
	{
        	printf("Enter x coordinate at #%d position: ", i + 1);
        	scanf("%f", &ptr[i].x);
        	printf("Enter y coordinate at #%d position: ", i + 1);
        	scanf("%f", &ptr[i].y);
    	}
}

/* start of read_structure function */
void read_structure(Point *ptr, int size) 
{
    	for (int i = 0; i < size; i++) 
	{
        	printf("The coordinates at #%d are (%f, %f)\n", i + 1, ptr[i].x, ptr[i].y);
    	}
}

/* start of line_length function */
void line_length(Point *ptr)
{
	printf("We are taking 2 points...\n");
	for (int i =0; i < 2; i++)
	{
		printf("The coordinates at #%d are (%f, %f)\n", i + 1, ptr[i].x, ptr[i].y);
        }

	double dist = sqrt(pow(ptr[0].x-ptr[1].x,2) + pow(ptr[0].y-ptr[1].y,2));
	printf("Distance between this 2 points is : %f\n",dist);


}
