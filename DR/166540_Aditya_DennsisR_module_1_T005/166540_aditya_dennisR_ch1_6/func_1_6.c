/* requird header files */
#include "header.h"
#include <stdio.h>

/* start of function */
void verify()
{
	int iChar;
        while (iChar = getchar() !=EOF)
		printf("in file:%d\n",iChar);
	printf("at EOF:%d\n",iChar);

}
/* end of function */
