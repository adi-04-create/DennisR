/*Exercise 1.16 - Print length of arbitrary long input line.c
author: Aditya Nathwani
created: 2 Jan 2025
modified: 2 Jan 2025*/
#include <stdio.h>

/*Define constant for maximum line length*/
#define MAXLINE 1000

/*Function prototypes*/
int mgetline(char line[], int lim);  /*Reads a line from input*/
void copy(char to[], char from[]);   /*copies a string from 'from' to 'to'*/

int main()
{
    int len, max;  
    char line[MAXLINE], maxline[MAXLINE];  

    max = 0;  

    /*Read lines until EOF is reached*/
    while ((len = mgetline(line, MAXLINE)) > 0)
    {
        /*If the current line is longer than the previous longest, update max and copy the line*/
        if (len > max)
        {
            max = len;       /*Update the maximum length*/
            copy(maxline, line);  /*Copy the current line into maxline*/
        }
    }

    /*If we have read any lines, print the longest line*/
    if (max > 0)
        printf("%s", maxline);  /*Output the longest line*/

    return 0;  
}

/*
* mgetline: Reads a line of input from stdin, and returns the length of the line.
* 's[]' is the array to store the line, and 'lim' is the maximum allowed length of the line.
* The function stops reading when a newline ('\n'), EOF, or the maximum length is reached.
*/
int mgetline(char s[], int lim)
{
    int i, c;  /*'i' is the index*/

    /*Read characters one by one until EOF, newline, or the maximum length is reached*/
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;  /*Store the character into the array*/

    /*If a newline is encountered, store it as well*/
    if (c == '\n')
    {
        s[i] = c;  /*Store the newline character*/
        ++i;       /*Increment the index after storing the newline*/
    }

    s[i] = '\0';  /*Null-terminate the string to mark the end of the line*/
    return i;     /*Return the length of the line (including newline if present)*/
}

/*
* copy: Copies the string from 'from' to 'to'.
* The function stops when it reaches the null-terminator of the 'from' string.
*/
void copy(char to[], char from[])
{
    int i = 0;  /*Initialize index*/

    /*Copy each character from 'from' to 'to' until the null-terminator is reached*/
    while ((to[i] = from[i]) != '\0')
        ++i;  /*Increment the index after each copy*/
}

