/* Revise minprintf to handle more of the other facilities of printf
 *
 * Author  : Aditya Nathwani
 * Created : 6th April, 2025
 */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Enhanced minprintf: supports many standard printf format specifiers */
void minprintf(const char *fmt, ...) {
	va_list ap;
	const char *p;
	char format[100];  // Buffer to build full format like "%5.2lf"
	va_start(ap, fmt);

	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		char *f = format;
		*f++ = '%';

		// Collect full format specifier (flags, width, precision, etc.)
		p++;  // Move past '%'
		while (*p && strchr("0123456789.-+ #lLzjh", *p)) {
			*f++ = *p++;
		}

		*f++ = *p;  // Add final format character (e.g., 'd', 'f', etc.)
		*f = '\0';  // Null-terminate

		/* Handle format types */
		switch (*p) {
			case 'd':
			case 'i':
				printf(format, va_arg(ap, int));
				break;
			case 'u':
				printf(format, va_arg(ap, unsigned int));
				break;
			case 'f':
				printf(format, va_arg(ap, double));
				break;
			case 'c':
				printf(format, va_arg(ap, int));  // char is promoted to int
				break;
			case 's':
				printf(format, va_arg(ap, char *));
				break;
			case 'p':
				printf(format, va_arg(ap, void *));
				break;
			case 'l':  // 'l' is already handled in the loop, this catches ld, lu, lf
				if (*(p + 1) == 'd') {
					p++;
					printf(format, va_arg(ap, long));
				} else if (*(p + 1) == 'u') {
					p++;
					printf(format, va_arg(ap, unsigned long));
				} else if (*(p + 1) == 'f') {
					p++;
					printf(format, va_arg(ap, double));
				}
				break;
			default:
				// Just print the unknown format character
				putchar('%');
				putchar(*p);
				break;
		}
	}

	va_end(ap);
}

int main() {
	minprintf("Testing minprintf:\n");
	minprintf("Integer (%%d):\t\t\t%d\n", 10);
	minprintf("Unsigned Integer (%%u):\t\t%u\n", 20);
	minprintf("Float (%%f):\t\t\t%.2f\n", 3.14f);
	minprintf("String (%%s):\t\t\t%s\n", "Hello");
	minprintf("Pointer (%%p):\t\t\t%p\n", (void *)0x123456);
	minprintf("Character (%%c):\t\t\t%c\n", 'A');
	minprintf("Long Integer (%%ld):\t\t%ld\n", 1234567890L);
	minprintf("Unsigned Long Integer (%%lu):\t%lu\n", 9876543210UL);
	minprintf("Double (%%lf)\t\t\t%lf:\n", 2.71828);

	return 0;
}
