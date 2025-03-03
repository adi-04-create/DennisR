/* required header files */
#include "head4.h"

/* start of function */
void celsiustofahrenheit(){

        float fahr, celsius;
	float lower, upper, step;
	printf("Hello World");
        lower = 0; // lower limit of temperatuire scale
        upper = 300; // upper limit
        step = 20; // step size

        celsius = lower;
        while (celsius <= upper)
        {
                fahr= ((9.0/5.0)* celsius)+32.0;
                printf("%6.1f\t %3.0f\n", celsius,fahr);
                celsius = celsius + step;                                                                 }
	
}
