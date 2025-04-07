#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN 1
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; 		/* pointer table */
struct nlist *lookup(char *); 
//char *strdup(char *); 

struct nlist { 						/* table entry: */ 
	struct nlist *next; 				/* next entry in chain */ 
	char *name; 					/* defined name */ 
	char *defn; 					/* replacement text */ 
};

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL; /* not found */
}


/* install: put (name, defn) in hashtab */ 
struct nlist *install(char *name, char *defn) 
{ 
	struct nlist *np; 
	unsigned hashval; 
	if ((np = lookup(name)) == NULL) { /* not found */ 
		np = (struct nlist *) malloc(sizeof(*np)); 
		if (np == NULL || (np->name = strdup(name)) == NULL) 
			return NULL; 
		hashval = hash(name); 
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np; 
	} else /* already there */ 
		free((void *) np->defn); /*free previous defn */ 
	if ((np->defn = strdup(defn)) == NULL) 
		return NULL; 
	return np; 
} 

void undef(char *name) 
{
	unsigned hashval = hash(name);
	struct nlist *prev = NULL;
	struct nlist *np = hashtab[hashval];

	while (np != NULL) 
	{
		if (strcmp(name, np->name) == 0) 
		{ 						// Found entry
			if (prev == NULL) 
			{ 					// Entry is first in list
				hashtab[hashval] = np->next;
			} 
			else 
			{ 					// Entry is in middle or end
				prev->next = np->next;
			}
			free(np->name);
			free(np->defn);
			free(np);
			return;
		}
		prev = np;
		np = np->next;
	}
}

//char *strdup(char *s) /* make a duplicate of s  
//{ 
//	char *p; 
//	p = (char *) malloc(strlen(s)+1); /* +1 for '\0'
//	if (p != NULL) 
//		strcpy(p, s); 
//	return p; 
//}

/* Testing the hash table */
int main() {
	install("MAX", "100");
	install("MIN", "1");
	install("PI", "3.14");
	install("TWO", "2");
	undef("TWO");
	struct nlist *entry;

	if ((entry = lookup("MAX")) != NULL)
		printf("MAX: %s\n", entry->defn);
	else
		printf("MAX not found\n");

	if ((entry = lookup("PI")) != NULL)
		printf("PI: %s\n", entry->defn);
	else
		printf("PI not found\n");

	if ((entry = lookup("UNKNOWN")) != NULL)
		printf("UNKNOWN: %s\n", entry->defn);
	else
		printf("UNKNOWN not found\n");

	if ((entry = lookup("TWO")) != NULL)
		printf("TWO: %s\n", entry->defn);
	else
		printf("TWO not found\n");

	return 0;
}
