#include <stdio.h>

int main()
{
	char var1 = 11;
	printf("Address = (%p) \n	(%d) \n	(%u) \n	(%c) \n	(%f) \n	(%x) \n	(%s) \n",&var1,&var1,&var1,&var1,&var1,&var1,var1);
	char *ptr ;
	ptr= &var1;
	printf("value = (%d) \n	(%p) \n	(%p) \n	(%d) \n	(%p) \n",*ptr,*ptr,&ptr,ptr,ptr);
        return 0;
}
