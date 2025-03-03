/* required header files */
#include <stdio.h>
#include <time.h>
#include <stdint.h>
/* start of function */
uint32_t binsearch(uint32_t x,uint32_t v[],uint32_t n)
{
	/* variables for clock */
        clock_t start, end;
        double cpu_time_used1,cpu_time_used2;
	
	/* variable decleration */
    	uint32_t low,high,mid;

	/* value assignment to variables */
    	low=0;
    	high=n-1;
    	mid = ( low + high ) / 2;

	/* start of clock for first while loop */
	start = clock();
	for (uint32_t i = 0; i < 100000; i++)
	{
		/* start of while loop with one test conditions inside the loop */
    		while(low < high && x != v[mid])
    		{
        		if( x > v[mid])
            			low = mid+1;
        		else
            			high = mid -1;

        		mid = ( low + high)/2;
    		}
	}
	end = clock();
	/* end of clock for first while loop */

	/* printing the time taken */
	cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Optimised Execution Time : %f seconds\n",cpu_time_used1);

	/* start of clock for second while loop */
	start = clock();
	for (uint32_t i = 0; i < 100000; i++)
	{
		/* start of while loop with two test condition inside the loop */
		while (low <= high)
		{
 			mid = (low+high)/2;
 			if (x < v[mid])
 				high = mid + 1;
 			else if (x > v[mid])
 				low = mid + 1;
 			else
 				return mid;
 		}
	}
	end = clock();
	/* end of clock for second while loop */

	/* printing the time taken */
	cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Original Execution Time : %f seconds\n",cpu_time_used2);

	/* returning the mid value */
    	if(x==v[mid])
        	return mid;
    	else
        	return -1;
}
/* end of function */

/* start of function */
//uint32_t bin(uint32_t x,uint32_t v[],uint32_t n)
//{
        /* variables for clock */
  //      clock_t start, end;
    //    double cpu_time_used;

        /* variable decleration */
      //  uint32_t low,high,mid;

        /* value assignment to variables */
        //low=0;
        //high=n-1;
        //mid = ( low + high ) / 2;

        /* start of clock for first while loop */
//        start = clock();
//	for (uint32_t i = 0; i < 100000; i++)
  //      {
                /* start of while loop with two test condition inside the loop */
    //            while (low <= high)
      //          {
        //                mid = (low+high)/2;
          //              if (x < v[mid])
            //                    high = mid + 1;
              //          else if (x > v[mid])
                //                low = mid + 1;
                  //      else /* found match 
                    //            return mid;
    //            }
      //  }
       // end = clock();
        /* end of clock for second while loop */

        /* printing the time taken */
  //      cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//        printf("Original Execution Time : %f seconds\n",cpu_time_used);

	/* returning the mid value */
    //    if(x==v[mid])
      //          return mid;
        //else
          //      return -1;
//}
/* end of function */



/* start of main program */

void array_search()
{
        /* variables for clock */
        //clock_t start, end;
        //double cpu_time_used;

        /* variable decleration */
        uint32_t x,n,result1,result2;
        uint32_t arry[n];
        printf("enter the max value of array of n:");
        scanf("%d",&n);

        /* for loop for getting the array */
        for (uint32_t i=0; i<=n; i++)
        {
                printf("enter the value of array position %d:",i);
                scanf("%d",&arry[i]);

        }
        printf("enter the value to search:");
        scanf("%d",&x);
        result1 = binsearch(x,arry,n);
	

  
        printf("if the x exist in the string it will return INDEX of the x or it will return(-1): %d\n",result1);
	//printf("if the x exist in the string it will return INDEX of the x or it will return(-1): %d\n",result2);
}
