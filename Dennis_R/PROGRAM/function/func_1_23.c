#include <stdio.h>
#include <stdlib.h>

#define NORMAL 0
#define SINGLE_QUOTE 1
#define DOUBLE_QUOTE 2
#define SINGLE_LINE_COMMENT 3
#define MULTI_LINE_COMMENT 4

void remove_comments(FILE *input, FILE *output);

void remove_comment() 
{
    	char filename[256];
    	printf("Enter the C file name: ");
    	scanf("%255s", filename);

    	FILE *input = fopen(filename, "r");
    	if (!input) 
	{
        	perror("Error opening input file");
        	return 1;
    	}

    	remove_comments(input, stdout);
    	fclose(input);
}

void remove_comments(FILE *input, FILE *output) 
{
    	int c, prev = 0;
    	int state = NORMAL;

    	while ((c = fgetc(input)) != EOF) 
	{
        	switch (state) 
		{
            		case NORMAL:
                		if (c == '/') 
				{
                    			int next = fgetc(input);
                    			if (next == '/') 
					{
                        			state = SINGLE_LINE_COMMENT;
                    			} 
					else if (next == '*') 
					{
                        			state = MULTI_LINE_COMMENT;
                    			} 
					else 
					{
                        			fputc(c, output);
                        			c = next;
                    			}
                		} 
				else if (c == '"') 
				{
                    			state = DOUBLE_QUOTE;
                    			fputc(c, output);
                		} 
				else if (c == '\'') 
				{
                    			state = SINGLE_QUOTE;
                    			fputc(c, output);
                		} else 
				{
                    			fputc(c, output);
                		}
                		break;
            
            		case SINGLE_QUOTE:
                		fputc(c, output);
                		if (c == '\'' && prev != '\\') 
				{
                    			prev = c;
                		} 
				else if (c == '\'') 
				{
                    			state = NORMAL;
                		}
                		break;
            
            		case DOUBLE_QUOTE:
                		fputc(c, output);
                		if (c == '\'' && prev != '\\') 
				{
                    			prev = c;
                		} 
				else if (c == '"') 
				{
                    			state = NORMAL;
                		}
                		break;
            
            		case SINGLE_LINE_COMMENT:
                		if (c == '\n') 
				{
                    			state = NORMAL;
                    			fputc(c, output);
                		}
                		break;

            		case MULTI_LINE_COMMENT:
                		if (c == '*' && (prev = fgetc(input)) == '/') 
				{
                    			state = NORMAL;
                		}
                		break;
        	}
        		prev = c;
    	}
}

