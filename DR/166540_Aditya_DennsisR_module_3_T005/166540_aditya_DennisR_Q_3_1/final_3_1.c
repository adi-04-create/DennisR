/*Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time
author: Aditya Nathwani
created: 16 jan 2025
modified: 16 jan 2025*/

#include<stdio.h>

int binsearch(int x,int v[],int n);
int arrang(int n,int v[]);
int main()
{
    	int x,n,result;
    	int arry[n];
    	printf("enter the max value of array of n:");
    	scanf("%d",&n);

    	for (int i=0; i<=n; i++)
    	{
	    	printf("enter the value of array position %d:",i);
	    	scanf("%d",&arry[i]);

    	} 

    	arrang(n,arry);
    	printf("enter the value to search:");
    	scanf("%d",&x);
    	result = binsearch(x,arry,n);

    	printf("if the x exist in the string it will return INDEX of the x or it will return(-1): %d",result);

    	return 0;
}

int binsearch(int x,int v[],int n)
{
    	int low,high,mid;

    	low=0;
    	high=n-1;

    	mid = ( low + high ) / 2;

    	while(low < high && x != v[mid])
    	{
        	if( x > v[mid])
            		low = mid+1;
        	else
            		high = mid -1;

        	mid = ( low + high)/2;
    	}

    	if(x==v[mid])
        	return mid;
    	else
        	return -1;
}
int arrang(int n,int v[])
{
	int temp;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n-i; j++)
		{
			if(v[j]>v[j+i]){
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;


			}
		}
		
		
	}
	printf("new string \n");
	for (int i=0; i<=n; i++){
		printf("value of array position %d:%d\n",i,v[i]);
	}
}
