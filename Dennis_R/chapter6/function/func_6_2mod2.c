#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 100
#define MAXWORD 100
#define DEFAULT_PREFIX_LEN 6  // Default comparison length

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
struct tnode *talloc(void);
void freetree(struct tnode *);
int getword(char *, int, FILE *);

int prefix_len = DEFAULT_PREFIX_LEN;  // Number of characters to compare

/* talloc: make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *)malloc(sizeof(struct tnode));
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int prefix) {
	int cond;
	char truncated[MAXWORD];

	strncpy(truncated, w, prefix);  // Extract the first 'prefix' characters
	truncated[prefix] = '\0';       // Null-terminate the string

	if (p == NULL) {
		p = talloc();
		p->word = strdup(truncated);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strncmp(truncated, p->word, prefix)) == 0) {
		p->count++;  // Repeated word with same prefix
	} else if (cond < 0) {
		p->left = addtree(p->left, w, prefix);
	} else {
		p->right = addtree(p->right, w, prefix);
	}
	return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim, FILE *fp) {
	int c;
	char *w = word;
	while (isspace(c = fgetc(fp)))  // Skip whitespace
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {  // Return single non-alphabetic characters
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++) {
		if (!isalnum(*w = fgetc(fp))) {
			ungetc(*w, fp);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* freetree: free all nodes in the tree */
void freetree(struct tnode *p) {
	if (p != NULL) {
		freetree(p->left);
		freetree(p->right);
		free(p->word);
		free(p);
	}
}

/* Main function to handle file input */
int main(int argc, char *argv[]) {
	struct tnode *root = NULL;
	char word[MAXWORD];

	if (argc < 2) {
		fprintf(stderr, "Usage: %s filename [prefix_length]\n", argv[0]);
		return 1;
	}

	if (argc == 3) {
		prefix_len = atoi(argv[2]);  // Get the prefix length from argument
		if (prefix_len <= 0 || prefix_len > MAXWORD) {
			fprintf(stderr, "Invalid prefix length. Using default: %d\n", DEFAULT_PREFIX_LEN);
			prefix_len = DEFAULT_PREFIX_LEN;
		}
	}

	FILE *inputFile = fopen(argv[1], "r");
	if (inputFile == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (getword(word, MAXWORD, inputFile) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word, prefix_len);
		}
	}

	fclose(inputFile);

	treeprint(root);
	freetree(root);  // Free allocated memory

	return 0;
}

