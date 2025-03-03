/* Write a program to print all input lines that are longer than 80 characters.
author: Aditya Nathwani
created: 31 December 2024
modified: 31 December 2024*/

/* required header files */
#include <stdio.h>

/* Define constants */
#define MAXLINE 1000  //Maximum input line size
#define LIMIT 80      //Limit for line length to be printed

/* 
* We call it ngetline, for new getline so that it does not conflict with the system function getline.
* This function is used to read a line of input from the user.
*/
int ngetline(char line[], int lim);

int main()
{
    //Declare variables
    int len;           //Variable to store the length of the current line
    char line[MAXLINE]; //Array to store the input line

    //Read lines of input until EOF is reached
    while ((len = ngetline(line, MAXLINE)) > 0) // Read each line and get its length
    {
        //If the length of the line is greater than the defined LIMIT, print the line
        if (len > LIMIT)
            printf("%s", line);  //Print the line
    }

    return 0; //End of program
}

/* 
* ngetline function: Reads a line of input from stdin.
* It takes two arguments: s[] (the array to store the line) and lim (the maximum length of the line).
* Returns the length of the line (number of characters read).
*/
int ngetline(char s[], int lim)
{
    int i, c;  //Declare variables for indexing (i) and character input (c)

    //Read characters one by one, stopping when we reach EOF, a newline, or the limit
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;  //Store the read character into the array

    //If a newline is encountered, store it in the array and increment the index
    if (c == '\n')
    {
        s[i] = c;  //Store the newline character
        ++i;       //Increment index to move past the newline
    }

    //Null-terminate the string
    s[i] = '\0';  //Mark the end of the string

    return i;  //Return the length of the string (including newline if it was read)
}

  
