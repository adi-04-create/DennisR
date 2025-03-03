// Program to remove trailing blanks and tabs from each line of input,and to delete entirely blank lines.
// Author: KAPATEL DHARM
// Created: 30 December 2024
// Modified: 30 December 2024

#include <stdio.h>   // Standard input/output library
//#include "header.h"   // Custom header file (assumed to contain necessary declarations)
#include <stdbool.h>  // Include for using the bool type for boolean values

int main()
{
    // Initialize variable to store the input character
    int c;

    // 'state' is a flag to track whether we are inside a non-blank region or not
    bool state = true;

    // While loop to read each character from input until EOF is encountered
    while ((c = getchar()) != EOF)
    {
        // Check if the character is a space or tab
        if (c == '\t' || c == ' ')
        {
            // If we are in a "non-blank state", print a single space and update the state
            if (state)
            {
                printf(" ");  // Replace space or tab with a single space
                state = false; // Mark the state as "blank" after printing the space
            }
        }
        else
        {
            // If the character is not a space or tab, reset state to true
            state = true;
            // Print the character as is (non-space/tab character)
            printf("%c", c);
        }
    }

    return 0;  // Return 0 to indicate successful execution
}
