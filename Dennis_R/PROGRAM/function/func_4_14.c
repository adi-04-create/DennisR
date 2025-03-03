/* Define a macro swap(t,x,y) that interchanges two arguments of type t.
 *
 * AUTHOR  : Aditya Nathwani
 * Created : 25 February, 2025
 */

/* required header files */
#include <stdio.h>

/* defination of swap macro */
#define swap(t, x, y) do { t temp = x; x = y; y = temp; } while (0)

/* start of swapping function */
void swapping() 
{
    	int a = 5, b = 10;
    //double p = 3.14, q = 2.71;

    	printf("Before swapping: a = %d, b = %d\n", a, b);
    	swap(int, a, b);
    	printf("After swapping: a = %d, b = %d\n", a, b);

    	//printf("Before swapping: p = %.2f, q = %.2f\n", p, q);
    	//swap(double, p, q);
    	//printf("After swapping: p = %.2f, q = %.2f\n", p, q);

    	//return 0;
}
/* end of swapping function */
