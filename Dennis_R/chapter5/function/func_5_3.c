// Required header files
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

/* Concatenate str2 to end of str1 using pointers */
void strcat_ptr(char *str1, const char *str2) 
{
	/* Move str1 pointer to the end of the string */
	while (*str1) 
	{
		str1++;
	}

	/* Copy str2 to str1 */
	while ((*str1++ = *str2++))  // copies a character and moves both pointers forward until EOF is reached
		;
}

int main() 
{
	char str1[MAX_LENGTH], str2[MAX_LENGTH];

	// User input 
	printf("Enter the first string: ");
	scanf("%99[^\n]", str1);
	getchar(); // Store the newline character

	printf("Enter the second string: ");
	scanf("%99[^\n]", str2);
	getchar(); 

	// Perform concatenation 
	strcat_ptr(str1, str2);

	printf("Result: %s\n", str1);

	return 0;
}
