/*Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
author: KAPATEL DHARM
created: 16 jan 2025
modified: 16 jan 2025*/
#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void itob(int n,char s[],int b);
void reverse(char s[]);

int main()
{
    int number,base;
    char str[MAXLINE];
    printf("enter the number:");
    scanf("%d",&number);
    printf("enter the base valu:");
    scanf("%d",&base);

    /*number=42425;*/
    /*base=16;*/

    itob(number,str,base);

    printf("%s\n",str);

    return 0;
}

void itob(int n,char s[],int b)
{
    int i,j,sign;

    if((sign=n)<0)
        n = -n;

    i = 0;

    do
    {
        j = n % b;

        s[i++] = (j <= 9)?j+'0':j+'a'-10;
    }while((n/=b)>0);

    if(sign < 0)
        s[i++]='-';

    s[i]='\0';

    reverse(s);
}

void reverse(char s[])
{
    int i,j,c;

    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}
