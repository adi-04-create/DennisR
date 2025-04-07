/* Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise

Author : Aditya Nathwani
Created : 9 March, 2025
 */

// Required header files
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_LENGTH 100

/* Function to check if str2 is a suffix of str1 */
int32_t is_suffix(const char *str1, const char *str2) 
{
	int32_t len1 = (int32_t)strlen(str1);
	int32_t len2 = (int32_t)strlen(str2);

	/* If str2 is longer than str1, it can't be a suffix */
	if (len2 > len1) 
	{
		return 0;
	}

	/* Compare last len2 characters of str1 with str2 */
	return strcmp(str1 + (len1 - len2), str2) == 0;
}

int main() 
{
	char str1[MAX_LENGTH], str2[MAX_LENGTH];

	/* User input */
	printf("Enter the first string: ");
	fgets(str1, MAX_LENGTH, stdin);

	printf("Enter the second string: ");
	fgets(str2, MAX_LENGTH, stdin);
	/* Check if str2 is a suffix of str1 */
	int32_t result = is_suffix(str1, str2);

	/* Print the result */
	printf("Return: %d"  "\n", result);

	return result;
}

