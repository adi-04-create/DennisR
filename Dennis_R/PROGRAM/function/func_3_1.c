/* Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
 *
 * Author : Aditya Nathwani
 * Created : 2, February, 2025
 * Modified : 20, February, 2025
 */

/* required header files */
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define NOT_FOUND UINT32_MAX 

/* start of binsearch program */
uint32_t binsearch(uint32_t x, uint32_t v[], uint32_t n) 
{
    	clock_t start, end;
    	double cpu_time_used1, cpu_time_used2;
    	uint32_t low, high, mid;

    	/* First binary search (optimized version) */
	/* start of clock */
    	start = clock();
    	for (uint32_t i = 0; i < 100000; i++) 
	{
        	low = 0;
        	high = n - 1;

        	while (low < high && x != v[mid]) 
		{
            		mid = (low + high) / 2;
            		if (x > v[mid])
                		low = mid + 1;
            		else
                		high = mid - 1;
        	}
    	}
    	end = clock();
	/* end of clock */
	/* time calculation */
    	cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    	printf("Optimized Execution Time: %f seconds\n", cpu_time_used1);

    	/* Second binary search (original method) */
	/* start of clock */
    	start = clock();
    	for (uint32_t i = 0; i < 100000; i++) 
	{
        	low = 0;
        	high = n - 1;

        
        while (low <= high) 
	{
            	mid = (low + high) / 2;

            	if (x < v[mid])
                	high = mid - 1;
            	else if (x > v[mid])
                	low = mid + 1;
            	else 
		{
                	break;
            	}
        	}
    	}
    	end = clock();
	/* end of clock */
	/* time calculation */
    	cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    	printf("Original Execution Time: %f seconds\n", cpu_time_used2);

    	return NOT_FOUND;
}

/* start of array_search function */
void array_search() 
{
    	uint32_t x, n;
    	printf("Enter the max value of array n: ");
    	scanf("%u", &n);

    	uint32_t arry[n];

    	for (uint32_t i = 0; i < n; i++) 
	{
        	printf("Enter the value of array position %u: ", i);
        	scanf("%u", &arry[i]);
    	}

    	printf("Enter the value to search: ");
    	scanf("%u", &x);

    	uint32_t result = binsearch(x, arry, n);

    	if (result == NOT_FOUND)
        	printf("Value not found in the array.\n");
    	else
        	printf("Value found at index: %u\n", result);
}
/* end of array search program */
/*
int main() 
{
    	array_search();
    	return 0;
}
*/
