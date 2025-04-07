/* Required header files */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND -1

/* Optimized Binary Search */
uint32_t binsearch(uint32_t x, uint32_t v[], uint32_t n)
{
    clock_t start, end;
    double cpu_time_used1, cpu_time_used2;
    uint32_t low, high, mid;

    /* First binary search (optimized version) */
    start = clock();
    for (uint32_t i = 0; i < 100000; i++)
    {
        low = 0;
        high = n - 1;

        while (low <= high) // Fixed condition
        {
            mid = (low + high) / 2; // Ensure mid is initialized
            if (x > v[mid])
                low = mid + 1;
            else if (x < v[mid])
                high = mid - 1;
            else
                return mid; // Return index if found
        }
    }
    end = clock();
    cpu_time_used1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Optimized Execution Time: %f seconds\n", cpu_time_used1);

    /* Second binary search (original method) */
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
                return mid; // Return index if found
        }
    }
    end = clock();
    cpu_time_used2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Original Execution Time: %f seconds\n", cpu_time_used2);

    return NOT_FOUND;
}

/* Start of array_search function */
void array_search()
{
    uint32_t x, n;
    printf("Enter the max value of array n: ");
    scanf("%u", &n);

    if (n == 0)
    {
        printf("Array size must be greater than 0.\n");
        return;
    }

    uint32_t *arry = malloc(n * sizeof(uint32_t));
    if (!arry)
    {
        printf("Memory allocation failed!\n");
        return;
    }

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

    free(arry); // Free allocated memory
}

int main()
{
	array_search();
	return 0;
}
