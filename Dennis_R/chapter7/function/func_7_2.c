/* Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom and break long text lines.
 *
 * Author  : Aditya Nathwani
 * Created : 6th April, 2025
 */

/* required header files */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 80
#define HEXLEN 4  /* one formatted non-graphic char */

int inc(int pos, int n) 
{
	if (pos + n >= MAXLINE) 
	{
		putchar('\n');
		return n;
	} 
	else 
	{
		return pos + n;
	}
}

int main() 
{
	char buffer[MAXLINE + 1];
	int pos;
	int c;

	while (1) 
	{
		printf("Enter text (press Enter to print, or Ctrl+D/Ctrl+Z to exit):\n");

		if (fgets(buffer, sizeof(buffer), stdin) == NULL) 
		{
			break;
		}

		printf("Output:\n");
		pos = 0;

		for (int i = 0; buffer[i] != '\0'; ++i) 
		{
			c = buffer[i];
			if (!isprint(c)) 
			{
				pos = inc(pos, HEXLEN + 7);
				printf("[0x%02X|0%03o]", c, c);
			} 
			else 
			{
				pos = inc(pos, 1);
				putchar(c);
			}
		}

		if (pos != 0 && buffer[strlen(buffer) - 1] != '\n') 
		{
			putchar('\n');
		}

		putchar('\n');
	}

	return 0;
}

