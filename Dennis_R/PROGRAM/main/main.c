/* This is the CENTRAL FILE for all the functions being used in all the function files 
 * Author : Aditya Nathwani
 * Created : 4 February, 2025
 * Modified : 5 February, 2025
 */

/* required header file */
#include "header.h"
#include <string.h>
#include <stdint.h>
/* start of main program */
int main()
{
	/* here all the function are declared which are being used in all the function files */
	/* This approch uses switch cases to ask from user which chapter and which program   */


	/* variable decleration */
	char chapter_input[5],program_input1[5],program_input2[5],program_input3[5],program_input[5];
	char chapter,program1,program2,program3,program4;
	/* start of while loop */
//	while(1)
//	{
		printf("Enter Chapter Number or press q to exit : ");
		scanf("%s",chapter_input);

		/* comparing both the strings */
		if(strcmp(chapter_input, "q") == 0)
		{
			printf("Exiting...\n");
			//break;
			return 0;
		}
		/* counvering string to integer */
		chapter = atoi(chapter_input);

		/* start of switch case for chapters */
		switch(chapter)
		{
			case 1:
				printf("Enter Program Number for chapter 1 or press q to exit: ");
				scanf("%s",program_input);

				if(strcmp(program_input1, "q") == 0)
                		{
                        		printf("Exiting...\n");
                        		break;
                		}

                		program1 = atoi(program_input1);
				
				/* start of switch case for programs for chapter 1 */
				switch(program1)
				{
				case 3:
					/* func_1_3.c */
					/* Temprature conversion from fahrenheit to celsius */
					fahrenheittocelsius();
					break;
				case 4:
					/* func_1_4.c */
					/* Temprature conversion from celsius to fahrenheit */
					celsiustofahrenheit();
					break;
				case 5:
					/* func_1_5.c */
					/* Temprature conversion from celsius to fahrenheit in reverse order */
					celsiustofahrenheitrev();
					break;
				case 6:
					/* func_1_6.c */
       					/* Verify that the expression getchar() != EOF is 0 or 1. */
					verify();
					break;
				case 7:
					/* func_1_7.c */
					/* Write a program to print the value of EOF. */
					print();
					break;
				case 8:
					/* func_1_8.c */ 
					/* Write a program to count blanks, tabs, and newlines. */
					char_count();
					break;
				case 9:
					/* func_1_9.c */ 
					/* copy input to output, replacing each string of one or more blanks by single blank. */
					singleblank();
					break;
				case 10:
					/* func_1_10.c*/
					/* replacing each tab by \t, each backspace by \b, and each backslash by \\. */
					find();
					break;
				case 11:
					/* func_1_11.c*/
					/* testing of word count program */
					wordcounting();
					break;
				case 12:
					/* func_1_12.c*/
					/* Write a program that prints its input one word per line */
					newline();
					break;
				case 13:
					/* func_1_13.c*/
					/* print a histogram of the lengths of words in its input */
					function();
					break;
				case 14:
					/* func_1_14.c*/
					/* print a histogram of the frequencies of different characters */
					func14();
					break;
				case 16:
					/* func_1_16.c*/
					/* prints the length of arbitary long input lines */
					longest_line();
					break;
				case 17:
					/* func_1_17.c*/
					/* print all the lines longer then 80 characters */
					longerline();
					break;
				case 18:
					/* func_1_18.c*/
					/* remove trailing blanks from a string */
					trim();
					break;
				case 19:
					/* func_1_19.c*/
					/* input string in reverse */
					revers();
					break;
				case 22:
					/* func_1_22.c*/
					/* Fold long input lines into shorter lines */
					fold();
					break;
				case 23:
					/* func_1_23.c*/
					/* remove comments from a given c program */
					remove_comment();
				default:
					printf("Exiting...\n");
					break;
				}
				break;
				/* end of switch case for programs in chapter 1 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/* start of switch case for programs of chapter 2 */
			case 2:
				printf("Enter Program Number for chapter 2 or press q to exit : ");
				scanf("%s",&program_input2);
				
				if(strcmp(program_input2, "q") == 0)
                                {
                                        printf("Exiting...\n");
                                        break;
                                }

                                program2 = atoi(program_input2);

				switch(program2)
				{
				case 1:
					/* func_2_1.c */
        				/* Defines the data ranges for all the data types are defined */
        				Data_Type_Size();
					break;
				case 2:
					/* func_2_2.c */
        				/* Function for a loop equivalent to the loop given in the example */
        				eqloop();
					break;
				case 3:
					/* func_2_3.c */
        				/* Converts a hexadecimal number to a decimal number */
        				hex();
					break;
				case 4:
					/* func_2_4.c */
        				/* Delete each character from string one which occures in the other string */
        				delete4();
					break;
				case 5:
        				/* func_2_5.c */
        				/* Returns the first location of the character in string 1 which is in string 2 */
        				location_return();
					break;
				case 6:
					/* func_2_6.c */
        				/* returns x with the n bits that begin at position p set to the rightmost n bits of y, */
        				setbit();
					break;
				case 7:
					/* func_2_7.c */
        				/* similar to previous question, instead here the defined bits are inverted */
        				bit_invert();
					break;
				case 8:
					/* func_2_8.c*/
        				/* rotate a given number by a defined position */
        				right_rotate();
					break;
				case 9:
					/* func_2_9.c*/
        				/* counts the occurance of 1 in output */
        				count();
					break;
				case 10:
					/* func_2_10.c*/
        				/* To convert upper case to lower case without if-else */
        				upper2lower();
					break;
				default:
					printf("Exiting...\n");
					break;
				}
				break;
				/* end of switch case for programs of chapter 2 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/* start of switch case for program of chapter 3 */
			case 3:
				printf("Enter Program Number for chapter 3 or press q to exit : ");
				scanf("%s",&program_input3);
				if(strcmp(program_input3, "q") == 0)
				{
					printf("Exiting...\n");
					break;
				}
				program3 = atoi(program_input3);
				switch(program3)
				{
					case 1:
						/* func_3_1.c */
						/* to search a perticular element from array with two different loops */
						array_search();
						break;
					case 2:
						/* func_3_2.c */
						/* catches the escape characters from the lines and printd them */
						//char_catch();
						break;
					case 3:
						/* func_3_3.c */
						/* expands the input in the form a-z */
						expansion();
						break;
					case 4:
						/* func_3_4.c */
						/* returns the value of the longest integer */
						returnval1();
						break;
					case 5:
						/* func_3_5.c */
						/* convert hex to binary */
						conversion();
						break;
					case 6:
						/* func_3_6.c */
						/* itoa with the modification of field width */
						field_modified();
					default:
						printf("Exiting...\n");
						break;
				}
				break;
				/* end of switch case for program of chapter 3 */

			/* start of switch case for program of chapter 4 */
			case 4:
				printf("Enter Program Number for chapter 4 or press q to exit : ");
                                scanf("%s",&program_input);
                                if(strcmp(program_input, "q") == 0)
                                {
                                        printf("Exiting...\n");
                                        break;
                                }
                                program4 = atoi(program_input);
                                switch(program4)
				{
					case 1:
						/* func_4_1.c */
						/* returns the rightmost index of a character in the string */
						strindex();
						break;
					case 2:
						/* func_4_2.c */
						/* for scientfic expression calculation */
						expression();
						break;
					case 3:
						/* func_4_3.c */
						/* stack operations with added modulus operation */
						//stack_operation2();
						printf("No function file for Question 3..\nExecute manually\n");
						break;
					case 4:
						/* func_4_4.c */
						/* to add more functionalities to the stack operations */
						//stack_operation2();
						printf("No function file for Question 4..\nExecute manually\n");
						break;
					case 5:
						/* func_4_5.c */
						printf("No function file for Question 5..\nExecute manually\n");
						break;

					case 6:
						/* func_4_6.c */
						/* add commands for handling variables */
						ExecuteCalculator();
						break;

					case 7:
						/* func_4_7.c */
						/* Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch? */
						unget_string();
						break;
					case 8:
						/* func_4_8.c */
						/* modified version of getch and ungetch functions */
						modified_version();
						break;

					case 9:
						/* func_4_9.c */
						/* to handle EOF perfectly */
						ProcessCharacter1();
						break;
					case 10:
						/* func_4_10.c*/
						/* use getline to read an entire input line */
						ExecuteCalculator1();
						break;
					case 11:
						/* func_4_11.c*/
						/* modify getop to remove ungetch */
						ProcessInput1();
						break;
					case 12:
						/* func_4_12.c*/
						/* recursive version of itoa */
						ExecuteItoa();
						break;

					case 13:
						/* func_4_13.c*/
						/* Write a recursive version of the function reverse(s), which reverses the string s in place. */
						reverse_func();
						break;
					case 14:
						/* func_4_14.c*/
						/* define a macro to swap to variables */
						swapping();
						break;
				}
				break;
				/* end of switch case for program of chapter 4 */
			default:
				printf("Exiting...\n\n");
				break;
		}
		/* end of switch case for chapter */
//	}
	/* end of while loop */
	return 0;
}
/* end of main program */
