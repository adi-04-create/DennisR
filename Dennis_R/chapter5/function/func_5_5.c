#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000
void mystrncpy(char *,char *,int);
void mystrncat(char *, char *, char *, int);
int mystrncmp(char *, char *, int);

int mystrlen(char *s);

int main(int argc, char *argv[])
{
	char dest[20] = {0};
	char source[20] = {0};
	int num;
	printf("Enter first string  : ");
	scanf("%s",dest);
	printf("Enter second string : ");
	scanf("%s",source);
	printf("Enter a number      : ");
	scanf("%d",&num);
	//char dest[]="ABCDEF";
	//char source[]="GHIJ";

	mystrncpy(dest,source,num);
	printf("%s\n",dest);

	char s1[]= "ABCD";
	char t1[]= "EFGHIJ";
	char *d;

	/* We store the result in a new string d */

	if ((d = (char *) malloc(sizeof(char) * (strlen(s1) + + 4 + 1))) == NULL) {
		printf("unable to allocate memory \n");
		return -1;
	}

	mystrncat(s1,t1,d, 4);
	printf("%s\n", d); /* ABCDEFGH */

	free(d);

	char s2[]= "ABCDEF";
	char t2[]= "ABC";
	int result;

	result = mystrncmp(s2,t2,3);

	printf("%d\n", result);


	return 0;
}

void mystrncat(char *str1, char *str2, char *dest, int n) {
	while(*str1) {
		*dest++ = *str1++;
	}

	while(n-- >0) {
		*dest++ = *str2++;
	}

	*dest = '\0';
}

void mystrncpy(char *dest,char *source,int n)
{
	while(*source && n-- > 0)
		*dest++ = *source++;

	int extra = mystrlen(dest) - n;

	while (extra-- > 0) {
		*dest++;
	}

	*dest = '\0';
}

/* mystrcmp: return <0 if s <t , 0 if s==t, > 0 if s > t */
int mystrncmp(char *lhs,char *rhs, int n)
{
	for(; *lhs == *rhs; lhs++,rhs++)
		if( *lhs == '\0' || --n <=0)
			return 0;
	return *lhs - *rhs;

}


int mystrlen(char *s) {
	char *p = s;
	while (*s != '\0') {
		s = s + 1;
	}
	return s - p;
}
