#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

#define abs(x) ((x) > 0 ? (x) : -(x))

void itoa(long int n, char s[], int f);
void reverse1(char s[]);

void returnval()
{
    long int number;
    char str[MAXLINE];
    int field;

    number = -2100; // Test negative numbers as well
    printf("Enter Field width: ");
    scanf("%d", &field);
    printf("Integer %ld printed as String: ", number);

    itoa(number, str, field);
    printf("%s\n", str);
}

void itoa(long int n, char s[], int f)
{
    long int i, sign;
    sign = n;
    i = 0;

    do
    {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    // Add padding spaces if needed
    while (i < f)
        s[i++] = ' ';

    s[i] = '\0';

    reverse1(s);
}

void reverse1(char s[])
{
    long int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void field_modified()
{
    returnval();
}

