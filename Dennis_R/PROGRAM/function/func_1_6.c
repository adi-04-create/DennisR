#include <stdint.h>
/* requird header files */
#include "header.h"
#include <stdio.h>

/* start of function */
void verify()
{
	printf("Verify that the expression getchar() != EOF is 0 or 1.");
	uint32_t iChar;
        while (iChar = getchar() !=EOF)
		printf("in file:%d",iChar);
	printf("at EOF:%d",iChar);

}
/* end of function */
