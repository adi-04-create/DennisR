/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
* Author: Aditya Nathwani
* Created: 31 December, 2024
* Modified: 2 January, 2025
*/

/*equired header file*/
#include <stdio.h>
#include "header_1_13.h"

/*Starting of main function*/
int main()
{
    /*Variable declaration and initialization*/
//    int c;                
  //  int iWordlength = 0;  
    //int jWordcount = 0;   
//    int max = 0;          
  //  int freq[1000] = {0}; 
    
    
    //printf("Enter a string:\n");

    
    /*The loop will continue until the user enters EOF (End Of File)*/
    //while ((c = getchar()) != EOF)
    //{
        /*If the character is not a space, tab, or newline, it's part of a word*/
      //  if (c != '\n' && c != '\t' && c != ' ')
        //{
            
       //   //  iWordlength++;
       /// }
        //else
        //{
            /*If a space or other separator is encountered, update the frequency of the word length*/
          //  freq[iWordlength]++;
            
            /*Update the maximum word length if needed*/
            //if (iWordlength > max)
          //  {
            //    max = iWordlength;
          //  }
            
            /*Reset the word length counter to 0 for the next word*/
            //iWordlength = 0;
       // }
   //; }

    /*Output the histogram of word lengths*/
    
    //for (jWordcount = 0; jWordcount <= max; jWordcount++)
    //{
        /*Print the word length (index)*/
      //  printf("%d : ", jWordcount);
        
        /*For each word length, print stars (*) corresponding to the frequency*/
        //for (int i = 0; i < freq[jWordcount]; i++)
        //{
         //   printf("*");
        //}
        
        /*Move to the next line after printing stars for each word length*/
        //printf("\n");
    //}
 


	printf("\tFrequency of lengths of word.\n\n");	

	function();
    	return 0; 
}

