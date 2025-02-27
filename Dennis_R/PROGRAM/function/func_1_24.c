#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 1000

void check_syntax(FILE *input);

void syntax_check() 
{
    	char filename[256];
    	printf("Enter the C file to check: ");
    	scanf("%255s", filename);

    	FILE *input = fopen(filename, "r");
    	if (!input) 
	{
        	perror("Error opening file");
        	return 1;
    	}

    	check_syntax(input);
    	fclose(input);
    	return 0;
}

void check_syntax(FILE *input) 
{
    	int c, prev = 0;
    	int parentheses = 0, brackets = 0, braces = 0;
    	int in_single_quote = 0, in_double_quote = 0, in_comment = 0;

    	while ((c = fgetc(input)) != EOF) 
	{
        	if (in_comment) 
		{
            		if (prev == '*' && c == '/') 
			{
                		in_comment = 0;
            		}
        	} 
		else if (in_single_quote) 
		{
            		if (c == '\\' && (prev = fgetc(input)) != EOF) 
			{
                		continue; // Skip escaped character
            		} 
			else if (c == '\'') 
			{
                		in_single_quote = 0;
            		}
        	} 
		else if (in_double_quote) {
            if (c == '\\' && (prev = fgetc(input)) != EOF) {
                continue; // Skip escaped character
            } else if (c == '"') {
                in_double_quote = 0;
            }
        } else {
            if (c == '/') {
                int next = fgetc(input);
                if (next == '/') {
                    while ((c = fgetc(input)) != EOF && c != '\n'); // Skip line comment
                } else if (next == '*') {
                    in_comment = 1;
                } else {
                    ungetc(next, input);
                }
            } else if (c == '\'') {
                in_single_quote = 1;
            } else if (c == '"') {
                in_double_quote = 1;
            } else if (c == '(') {
                parentheses++;
            } else if (c == ')') {
                parentheses--;
            } else if (c == '[') {
                brackets++;
            } else if (c == ']') {
                brackets--;
            } else if (c == '{') {
                braces++;
            } else if (c == '}') {
                braces--;
            }
        }
        prev = c;
    }

    if (parentheses != 0) {
        printf("Mismatched parentheses!\n");
    }
    if (brackets != 0) {
        printf("Mismatched brackets!\n");
    }
    if (braces != 0) {
        printf("Mismatched braces!\n");
    }
    if (in_single_quote) {
        printf("Unclosed single quote!\n");
    }
    if (in_double_quote) {
        printf("Unclosed double quote!\n");
    }
    if (in_comment) {
        printf("Unclosed comment!\n");
    }
    if (parentheses == 0 && brackets == 0 && braces == 0 && !in_single_quote && !in_double_quote && !in_comment) {
        printf("No syntax errors found!\n");
    }
}

