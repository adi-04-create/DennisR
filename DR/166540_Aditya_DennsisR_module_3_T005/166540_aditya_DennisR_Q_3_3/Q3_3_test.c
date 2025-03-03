#include<stdio.h>
#define MAXLINE 100

int mgetline(char s[],int maxlimit);
void expand(char s1[],char s2[]);

int main()
{
    char s1[MAXLINE],s2[MAXLINE];

    mgetline(s1,MAXLINE);

    expand(s1,s2);

    printf("%s",s2);

    return 0;
}

int mgetline(char s[],int lim)
{
    s[lim] = {0};
    int i;

    int	c;

    while((c = getchar()) != EOF)
    {
         s[i]=c;
         i++;

    }
}

void expand(char s1[],char s2[])
{
    int i,j,c;

    i=j=0;

    while((c=s1[i++]) != '\0')
        if(s1[i]=='-' && s1[i+1] >=c)
        {
            i++;
            while(c<s1[i])
            s2[j++]=c++;
        }
        else
            s2[j++]=c;

    s2[j]='\0';
}
