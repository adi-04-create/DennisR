/* Write a private version of scanf analogous to minprintf from the previous 
section.

Author  : Aditya Nathwani
Created : 6th April, 2025
*/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void minscanf(const char *fmt, ...) {
	va_list ap;
	const char *p;
	char format[100];  // Buffer to build format specifier (e.g., "%5.2lf")
	va_start(ap, fmt);

	for (p = fmt; *p; p++) {
		if (*p != '%') continue;  // Skip non-format characters

		char *f = format;
		*f++ = '%';

		// Build full format string
		p++;  // skip '%'
		while (*p && strchr("0123456789.-+ #lLzjh", *p)) {
			*f++ = *p++;
		}

		*f++ = *p;  // Format specifier
		*f = '\0';

		// Handle specifier and read input
		switch (*p) {
			case 'd':
			case 'i':
				scanf(format, va_arg(ap, int *));
				break;
			case 'u':
				scanf(format, va_arg(ap, unsigned int *));
				break;
			case 'f':
			case 'g':
			case 'e':
				scanf(format, va_arg(ap, float *));
				break;
			case 'lf':
				scanf(format, va_arg(ap, double *));
				break;
			case 'c':
				scanf(format, va_arg(ap, char *));
				break;
			case 's':
				scanf(format, va_arg(ap, char *));
				break;
			case 'l':
				if (*(p + 1) == 'd') {
					p++;
					*f++ = *p;
					*f = '\0';
					scanf(format, va_arg(ap, long *));
				} else if (*(p + 1) == 'u') {
					p++;
					*f++ = *p;
					*f = '\0';
					scanf(format, va_arg(ap, unsigned long *));
				} else if (*(p + 1) == 'f') {
					p++;
					*f++ = *p;
					*f = '\0';
					scanf(format, va_arg(ap, double *));
				}
				break;
			default:
				// Unknown specifier - skip
				break;
		}
	}

	va_end(ap);
}
int main() {
	int i;
	float f;
	char str[100];
	char ch;

	printf("Enter an integer, float, string, and character: ");
	minscanf("%d %f %s %c", &i, &f, str, &ch);

	printf("You entered:\n");
	printf("Integer: %d\n", i);
	printf("Float: %.2f\n", f);
	printf("String: %s\n", str);
	printf("Character: %c\n", ch);

	return 0;
}

