
#include <stdio.h>
#include <string.h>
#define MAXIMUM 1000

int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXIMUM];
    while ((len = getLine(line, MAXIMUM)) > 0){
        printf("%d", len);
    }
    return 0;
}

int getLine(char s[], int lim)
{
    int i, j, c;
    for (i = 0, j = 0; i < lim - 1; i++, j++)
    {
        if ((c = getchar()) == EOF)
            i = lim;
        else if (c == '\n')
            i = lim;
        s[j] = c;
    }
    if (c == '\n')
    {
        s[j] = c;
        j++;
    }
    s[j] = '\0';
    return j;
}

