/* required header files */
#include <stdio.h>

/* function prototype */
void output(float, float *, float *);

/* start of main function */
uint32_t main()
{
	/* variable decleration */
	float radius,area,perimeter;
	printf("Enter radius of circle : ");
	scanf("%f",&radius);

	/* calling the function */
	output(radius,&area,&perimeter);
	printf("area = %f\n",area);
	printf("perimeter = %f\n",perimeter);
	return 0;
}
/* end of main function */

/* start of output function */
void output(float radius,float *area,float *perimeter)
{
	/* values at the address of area and perimeter variables will be updated */
	*area = 3.14*radius*radius;
	*perimeter = 2*3.14*radius;
}
/* end of output function */

