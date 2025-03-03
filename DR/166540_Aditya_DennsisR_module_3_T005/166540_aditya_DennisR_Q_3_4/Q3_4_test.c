#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

#define abs(x) ( (x) > 0 ? (x): -(x))

void itoa(int n,char s[]);
void reverse(char s[]);


int main()
{
    int number;
    char str[MAXLINE];

 /* number=-2345645; */

    number = -2147483648;


    printf("Integer %d printed as\n String:",number);

    itoa(number,str);

    printf("%s",str);

    return 0;
}
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
   int i, sign;
   if ((sign = n) < 0) /* record sign */
            n = -n; /* make n positive */
            i = 0;
   do { /* generate digits in reverse order */
            s[i++] = n % 10 + '0'; /* get next digit */
      } 
   while ((n /= 10) > 0); /* delete it */
       if (sign < 0)
           s[i++] = '-';
       s[i] = '\0';
   reverse(s);
}
void reverse(char s[])
{
    int c,i,j;

    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}
