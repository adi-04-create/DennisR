#include <stdio.h>

int main()
{
/*	char var1 = 11;
	printf("Address = (%p) \n	(%d) \n	(%u) \n	(%c) \n	(%f) \n	(%x) \n	(%s) \n",&var1,&var1,&var1,&var1,&var1,&var1,var1);
	char *ptr ;
	ptr= &var1;
	printf("value = (%d) \n	(%p) \n	(%p) \n	(%d) \n	(%p) \n",*ptr,*ptr,&ptr,ptr,ptr);
	return 0;
*/
	
	int a;
	int i = 0;
	int j = 0;
	int l = 0;
	int k;
	int val = 0;
	char b;
	float c;
	double d;
	long int e;
	long long int f;
	short int g;
	int h = sizeof(a) + sizeof(b);
	
//	int val = 0;
//	int k;
//	int l = 0;
	//int l = 0;
	int Iarr[] = {10,20,0,40,50};
	char Carr[] = {10,20,30,40,50};
	int *ptr = Iarr;
	
	printf("size of integer       (a)   : %ld\n",sizeof(a));
	printf("size of character     (b)   : %ld\n",sizeof(b));
	printf("size of float         (c)   : %ld\n",sizeof(c));
	printf("size of double        (d)   : %ld\n",sizeof(d));
	printf("size of long int      (e)   : %ld\n",sizeof(e));
	printf("size of long long int (f)   : %ld\n",sizeof(f));
	printf("size of short int     (g)   : %ld\n",sizeof(g));
	printf("size of (a + b)             : %ld\n",sizeof(a+b));
	printf("size of (a + c)             : %ld\n",sizeof(a+c));
	printf("size of a + size of b (h)   : %d\n",h);
	printf("size of 'a'                 : %ld\n",sizeof'a');
	printf("size of \"a\"                 : %ld\n",sizeof"a");
	printf("size of 'b'                 : %ld\n",sizeof'b');
	printf("size of \"b\"                 : %ld\n",sizeof"b");
	
	printf("size of array         (Iarr): %ld\n",sizeof(Iarr));
	printf("address of array      (Iarr): %p\n",&Iarr);
	printf("size of array         (Carr): %ld\n",sizeof(Carr));
	printf("address of array      (Carr): %p\n",&Carr);
	while ( Iarr[i] )
	{
		printf("address of Iarr[%d]          : %p\n",i,&Iarr[i]);
		i++;
	}
	while ( Carr[j] )
	{
		printf("address of Carr[%d]          : %p\n",j,&Carr[j]);
		j++;
	}
	
	printf("Enter Index                 : ");
	scanf("%d",&k);
	printf("value at #%d is              : %d\n",k,Iarr[k]);
	printf("Enter a Value               : ");
	scanf("%d",&val);
	*(ptr + k) = val;
	printf("updated value at #%d is      : %d\n",k,Iarr[k]);
	
	while ( Iarr[l] )
        {
                printf("value at Iarr[%d]            : %d\n",l,Iarr[l]);
                l++;
        }
	return 0;
}
