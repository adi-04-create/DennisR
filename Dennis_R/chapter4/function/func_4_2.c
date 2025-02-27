/*#include <stdio.h> 
#include <ctype.h>
#define MAXLINE 100 */
/* rudimentary calculator */ 
/*void convert() 
{ 
	double sum, atof(char []); 
	char line[MAXLINE]; 
	int getline(char line[], int max); 
	sum = 0; 
	while (getline(line, MAXLINE) > 0) 
		printf("\t%g\n", sum += atof(line));  
}
*/
 
/* atof: convert string s to double */ 
/*double atof(char s[]) 
{ 
	double val, power; 
	int i, sign; 
	for (i = 0; isspace(s[i]); i++)*/ /* skip white space */ 
/*	; 
	sign = (s[i] == '-') ? -1 : 1; 
	if (s[i] == '+' || s[i] == '-') 
		i++; 
	for (val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0'); 
	if (s[i] == '.') 
		i++; 
	for (power = 1.0; isdigit(s[i]); i++) 
	{ 
		val = 10.0 * val + (s[i] - '0'); 
		power *= 10; 
	} 
	return sign * val / power; 
} */

/* required header files */
#include <stdio.h>
#include <ctype.h>

#define MAXLEN 500

/* prototype decleration of function */
int get_line(char line[], unsigned int max_line_len);
double atof(char s[]);

/* start of main function */
void expression()
{
	printf("Enter an expression : ");
	char line[MAXLEN];

  	get_line(line, MAXLEN);
  	printf("%s", line);

  	printf("%f", atof(line));


}
/* end of main function */

/* start of get line function */
int get_line(char line[], unsigned int max_line_len)
{
  	int index = 0, ichar;

	/* while loop for getting the expression */
  	while (index < max_line_len - 1 && (ichar = getchar()) != '\n' && ichar != EOF)
  	{
    		line[index] = ichar;
    		++index;
  	}

	/* if we get a new line than also increament the index of string */
  	if (ichar == '\n')
  	{
    		line[index++] = ichar;
  	}

	/* terminating character for a string */
  	line[index] = '\0';

  	return index;
}
/* end of get line function */

/* start of atof function */
double atof(char s[])
{
  	double val, power;
  	int index, sign, exp_sign = 1, exp_pwr = 0;

	/* checking for spaces and ignoring them */
  	for (index = 0; isspace(s[index]); ++index)
    	;

	/* setting the sign variable for latter use */
  	sign = (s[index] == '-') ? -1 : 1;

	/* if we get + or - sign then increament the index */
  	if (s[index] == '+' || s[index] == '-')
  	{
    		++index;
  	}

	/* for taking the whole number */
  	for (val = 0.0; isdigit(s[index]); ++index)
  	{
    		val = 10.0 * val + (s[index] - '0');
  	}

	/* including the decimal point */
  	if (s[index] == '.')
  	{
    		++index;
  	}

	/* implying power to the decimal number */
  	for (power = 1.0; isdigit(s[index]); ++index)
  	{
    		val = 10.0 * val + (s[index] - '0');
    		power *= 10;
  	}

	/* format of getting the string */
  	if (s[index] == 'e' || s[index] == 'E')
  	{
    		if (s[++index] == '-')
    		{
      			exp_sign = -1;
      			++index;
    		}
  	}

	/* applying exponential power to the expression */
  	while (isdigit(s[index]))
  	{
    		exp_pwr = 10 * exp_pwr + (s[index] - '0');
    		++index;
  	}

	/* setting the value of the power variable */
  	while (exp_pwr)
  	{
    		if (exp_sign == -1)
    		{
      			power *= 10;
    		}
    		else
    		{
      			power /= 10;
    		}

    		--exp_pwr;
  	}

	/* final return value */
  	return sign * val / power;
}
/* end of atof function */
