/* Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?
 *
 * Author   : Aditya Nathwani
 * Created  : 17 March, 2025
 * Modified : 19 March, 2025
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  /* max #lines to be sorted */
#define MAXLEN 1000    /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], char lines[][MAXLEN], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int get_line(char *, int);

/* sort input lines */
int main()
{
        char lines[MAXLINES][MAXLEN]; /* Storage for lines */
        int nlines; /* number of input lines read */

        if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
                qsort(lineptr, 0, nlines - 1);
                writelines(lineptr, nlines);
                return 0;
        } else {
                printf("error: input too big to sort\n");
                return 1;
        }
}

/* readlines: read input lines */
/*int readlines(char *lineptr[], int maxlines)
{
        int len, nlines;
        char *p, line[MAXLEN];

        nlines = 0;
        while ((len = get_line(line, MAXLEN)) > 0) {
                if (nlines >= maxlines || (p = alloc(len)) == NULL)
                        return -1;
                else
                {
                        line[len - 1] = '\0'; // delete newline 
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                }
        }
}*/


/* readlines: read input lines into a predefined 2D array */
int readlines(char *lineptr[], char lines[][MAXLEN], int maxlines)
{
        int len, nlines = 0;

        while (nlines < maxlines && (len = get_line(lines[nlines], MAXLEN)) > 0) {
                lines[nlines][len - 1] = '\0'; /* remove newline */
                lineptr[nlines] = lines[nlines]; /* point to stored line */
                nlines++;
        }

        return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
        for (int i = 0; i < nlines; i++)
                printf("%s\n", lineptr[i]);
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
        int c, i = 0;
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n' && i < lim - 1)
                s[i++] = c;
        s[i] = '\0';
        return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
        int i, last;
        void swap(char *v[], int i, int j);

        if (left >= right)
                return;

        swap(v, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++)
                if (strcmp(v[i], v[left]) < 0)
                        swap(v, ++last, i);
        swap(v, left, last);
        qsort(v, left, last - 1);
        qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
        char *temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}

