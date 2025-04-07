/* Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
 *
 * Author : Aditya Nathwani
 * Created : 20 March, 2025
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#define BUFSIZE 100
#define NUMBER '0' 				/* signal that a number was found */
char buf[BUFSIZE];                              /* buffer for ungetch */
int bufp = 0;                                   /* next free position in buf */
//void reverse(char s[]);
void *reverse(char *string);
int getch(void);
void ungetch(int c);

/* getline: read a line, return length */ 
/*int my_getline(char *line, int max) 
{ 
	if (fgets(line, max, stdin) == NULL) 
		return 0; 
	else 
		return strlen(line); 
}*/

/* getline: read a line, return length */
int my_getline(char *line, int max) 
{
    	char *p = line;
    	if (fgets(line, max, stdin) == NULL)
        	return 0;
    	while (*p)  // Find length using pointer arithmetic
        	p++;
    	return p - line;
}

/* atoi: convert string s to integer using atof */
/*int atoi(char s[])
{
	double atof(char s[]);
	return (int) atof(s);
}*/

/* atoi: convert string s to integer using atof */
int my_atoi(char *s) 
{
    	double my_atof(char *s);
    	return (int) my_atof(s);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0) 		/* record sign */
		n = -n; 		/* make n positive */
	i = 0;
	do { 				/* generate digits in reverse order */
		s[i++] = n % 10 + '0'; 	/* get next digit */
	} while ((n /= 10) > 0); 	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* itoa: convert n to characters in s using pointers */
void my_itoa(int n, char *s) 
{
    	char *p = s;
    	int sign = n;

    	if (n < 0)
        	n = -n;  		/* Make n positive */

    	do {
        	*p++ = n % 10 + '0';  	/* Get next digit */
    	} 
	while ((n /= 10) > 0);

    	if (sign < 0)
        	*p++ = '-';

    	*p = '\0';  			/* Null-terminate the string */
    	reverse(s); 			/* Reverse the string in-place */
}

/* atof: convert string s to double */
double my_atof(char *s) {
    	double val = 0.0, power = 1.0;
    int sign = 1;

    // Skip whitespace
    while (*s == ' ' || *s == '\t' || *s == '\n')
        s++;

    // Handle sign
    if (*s == '-' || *s == '+') {
        if (*s == '-')
            sign = -1;
        s++;
    }

    // Process integer part
    while (*s >= '0' && *s <= '9') {
        val = val * 10.0 + (*s - '0');
        s++;
    }

    // Process fractional part
    if (*s == '.') {
        s++;
        while (*s >= '0' && *s <= '9') {
            val = val * 10.0 + (*s - '0');
            power *= 10.0;
            s++;
        }
    }

    return sign * (val / power);
}

/* reverse: reverse string s in place */
/*void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	printf("Reversed String      : %s\n",s);
}*/

/* reverse: reverse string s in place */
void *reverse(char *string)
{
	int i,j;
	char temp;
	for( i=0,j=strlen(string)-1; i<j; i++,j-- )
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;		
	}
	printf("Reversed String      : %s\n",string);
}


/* strindex: return index of t in s, -1 if none */
/*int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}*/

/* start of strindex function */
char *strindex( char *string1, char *string2 )
{
        /* variable decleration and initialisation
         * array decleration and initialisation */
        char arr[50] = {0};
        uint16_t index = 0;
        uint16_t index1 = 0;
        uint16_t offset = 0;
        uint8_t op_arr[20] = {0};

        /* for ( i=0;i<strlen(string1);i++ ) */
        while ( *string1 )
        {
                offset++;
                if ( *string1 == *string2 )
                {


                        /* until the string matches we will store the matched
                         * characters in another array called op_arr */
                        printf("Matched at address   : %p\n",string1);
                        op_arr[index1++] = offset;
                        arr[index++] = *string1;
                        string1++;
                        string2++;
                        if ( *string1 != *string2 )
                        {
                        //      printf("%s\n",op_arr);
                                break;
                        }
                }
                else if ( *string1 != *string2 )
                {
                        string1++;
                }
        }

        printf("Matched string is    : %s\n",arr);
        printf("Index in string 1    : %d\n",*op_arr);
}
/* end of strindex function */

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)                                 /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)                             /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

int main()
{
	int index1 = 0;
	int index2 = 0;
	char ichar1, ichar2;
	char str1[50] = {0};
	char str2[50] = {0};

	printf("Enter a string       : ");
	while(( ichar1 = getchar() ) != '\n' )
	{
		str1[index1++] = ichar1;
	}
	printf("Enter another string : ");
	while(( ichar2 = getchar() ) != '\n' )
	{
		str2[index2++] = ichar2;
	}
	
	/*int val = strindex(str1, str2);
	printf("string 2 begins at %d index in string 1.\n",val);*/
	strindex(str1, str2);
	reverse(str1);
	return 0;
}

