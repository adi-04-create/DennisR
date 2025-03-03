/*Program to reverse input string line by line and print the reversed line
 Author: KAPATEL DHARM
 Created: 1 Jan 2024
 Modified: 1 Jan 2024*/

#include <stdio.h>   
#include "header.h"   
#define MAX 500       

/*Function to reverse the string*/
void revers()
{
    /*Variable initialization*/
    int i = 0;         
    int c[MAX] = {0};  

    /*Read characters from input until EOF is encountered*/
    while ((c[i] = getchar()) != EOF)
    {
        i++;  /*Increment index for the next character*/
    }

    /*Print the characters in reverse order*/
    for (int j = i - 1; j >= 0; j--)  /*Start from the last character and move backward*/
    {
        printf("%c", c[j]);  /*Print each character in reverse order*/
    }
}


//int main()
//{
  //  revers();  Call the function to reverse the input string
  //  return 0;  
//}
