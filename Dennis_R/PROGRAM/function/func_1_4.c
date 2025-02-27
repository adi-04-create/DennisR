#include <stdint.h>
/* required header files */
#include "header.h"
#include <stdio.h>

/* start of function */
void celsiustofahrenheit()
{
        float fahr, celsius;
        float lower, upper, step;

        lower = 0; // lower limit of temperatuire scale
        upper = 300; // upper limit
        step = 20; // step size

        celsius = lower;
//	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
//	printf("|\tCelsius\t\t|\tFahrenheit\t|\n");
	printf(" _______________________________________________ \n");
	printf("|\tCelsius\t\t|\tFahrenheit\t|\n");
	printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
        while (celsius <= upper)
        {
                fahr= ((9.0/5.0)* celsius)+32.0;
                printf("|\t%5.1f\t\t|\t%6.0f\t\t|\n", celsius,fahr);
		printf("|_______________________________________________|\n");
//		printf("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|\n");
                celsius = celsius + step;          
	}
//	printf("|_______________________________________________|\n");
}
/* end of function */
