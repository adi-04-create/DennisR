#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 50  /* max #lines to be sorted */
#define MAXLEN 100    /* max length of any input line */
int fold = 0;   // for -f
int directory = 0; // for -d

char *lineptr[MAXLINES]; /* pointers to text lines */

/* Function Prototypes */
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(void *, void *);
int my_getline(char *s, int lim);

/* Global function pointer for reverse sorting */
int (*original_comp)(void *, void *);

int reverse_wrapper(void *a, void *b) {
	return -original_comp(a, b);
}

int isdirchar(int c) {
    return isalnum(c) || isspace(c);
}

int numcmp(void *s1, void *s2) {
	double v1 = atof((char *)s1);
	double v2 = atof((char *)s2);
	return (v1 > v2) - (v1 < v2); // More compact comparison
}

int dircmp(void *s1, void *s2) {
    char *a = (char *)s1;
    char *b = (char *)s2;

    while (*a != '\0' || *b != '\0') {
        // Skip non-directory-order characters
        while (*a && !isdirchar(*a)) a++;
        while (*b && !isdirchar(*b)) b++;

        char ca = *a;
        char cb = *b;

        // Apply case folding if -f is on
        if (fold) {
            ca = tolower(ca);
            cb = tolower(cb);
        }

        if (ca != cb)
            return ca - cb;

        if (*a) a++;
        if (*b) b++;
    }
    return 0;
}


int foldcmp(void *s1, void *s2) {
    	char *a = (char *)s1;
    	char *b = (char *)s2;

    	for (; tolower(*a) == tolower(*b); a++, b++) {
        	if (*a == '\0')
            	return 0;
    	}
    	return tolower(*a) - tolower(*b);
}

int main(int argc, char *argv[])
{
	int nlines;      				/* number of input lines read */
	int numeric = 0; 				/* 1 if numeric sort */
	int reverse = 0; 				/* 1 if reverse sort */
/*	int fold = 0;  */					/* 1 if folding upper and lower case */
	/* Process command-line arguments */
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-n") == 0)
			numeric = 1;
		else if (strcmp(argv[i], "-r") == 0)
			reverse = 1;
		else if (strcmp(argv[i], "-f") == 0)
    			fold = 1;
		else if (strcmp(argv[i], "-d") == 0)
    			directory = 1;


	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		/*int (*comp)(void *, void *) = (int (*)(void *, void *))(numeric ? numcmp : (int (*)(void *, void *))strcmp);

		if (reverse) {
			original_comp = comp;
			comp = reverse_wrapper;
		}*/
		/*int (*comp)(void *, void *);
		if (numeric)
    			comp = numcmp;
		else if (fold)
    			comp = foldcmp;
		else
    			comp = (int (*)(void *, void *))strcmp;*/
		int (*comp)(void *, void *);
		if (numeric) {
    			comp = numcmp;
		} 
		else if (directory) {
    			comp = dircmp;
		} 
		else if (fold) {
    			comp = foldcmp;
		} 
		else {
    			comp = (int (*)(void *, void *))strcmp;
		}


		if (reverse) {
    			original_comp = comp;
    			comp = reverse_wrapper;
		}


		quick_sort((void **)lineptr, 0, nlines - 1, comp);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}
/* quick_sort: sort v[left]...v[right] into increasing order */
void quick_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);
	quick_sort(v, left, last - 1, comp);
	quick_sort(v, last + 1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j) {
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* my_getline: read a line into s, return length */
int my_getline(char *s, int lim) {
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

