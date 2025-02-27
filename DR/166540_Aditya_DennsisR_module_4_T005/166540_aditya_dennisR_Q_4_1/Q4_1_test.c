/*Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
author: KAPATEL DHARM
created: 21 jan 2025
modified: 21 jan 2025*/


#include<stdio.h>

int mstrindex(char source[],char searchfor[]);

int main()
{   char c;
    char line[100]={0};
    char pattern[10];
    int i,a;
   // printf("enter the string lenght");
    // scanf("%d",&a);
    printf("enter the string");
    //for(i=0; i<=a; i++){
    scanf("%s",line);
    }


    printf("the cheracter you want to find");
    scanf("%s",pattern);

    int found;

    

    found = mstrindex(line, pattern);

    printf("Found the right index: %d\n", found);

}

int mstrindex(char s[],char t[])
{
    int i,j,k, result;

    result = -1;

    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            result = i;
    }
    return result;
}
