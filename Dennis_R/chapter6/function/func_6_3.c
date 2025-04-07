#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXLINES 100  // Maximum number of line occurrences to store

// List of common noise words to ignore
const char *noise_words[] = {
	"the", "and", "a", "an", "of", "to", "in", "on", "at", "for", "with", "is", "was",
	"by", "that", "this", "it", "as", "be", "are", "or", "but", "from", "not", "so", NULL
};

// Structure for binary tree nodes
struct tnode {
	char *word;
	int lines[MAXLINES]; // Stores line numbers
	int line_count;      // Number of occurrences (line numbers stored)
	struct tnode *left;
	struct tnode *right;
};

// Function prototypes
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
void freetree(struct tnode *);
//int getword(char *, int, FILE *);
int getword(char *word, int lim, FILE *fp, int *line_num);
int is_noise_word(const char *word);
struct tnode *talloc(void);

/* Allocate memory for a new tree node */
struct tnode *talloc(void) {
	return (struct tnode *)malloc(sizeof(struct tnode));
}

/* Check if a word is a noise word */
int is_noise_word(const char *word) {
	for (int i = 0; noise_words[i] != NULL; i++) {
		if (strcmp(word, noise_words[i]) == 0) {
			return 1; // Word is a noise word
		}
	}
	return 0;
}

/* Add a word to the tree and store its line number */
struct tnode *addtree(struct tnode *p, char *w, int line) {
	int cond;

	if (p == NULL) {  // Create a new node
		p = talloc();
		p->word = strdup(w);
		p->line_count = 0;
		p->lines[p->line_count++] = line;
		p->left = p->right = NULL;
	} 
	else if ((cond = strcmp(w, p->word)) == 0) {  
		// Word already exists, store new line number if it's unique
		if (p->line_count < MAXLINES && p->lines[p->line_count - 1] != line) {
			p->lines[p->line_count++] = line;
		}
	} 
	else if (cond < 0) { 
		p->left = addtree(p->left, w, line);
	} 
	else { 
		p->right = addtree(p->right, w, line);
	}

	return p;
}

/* Get next word from input, track line number */
int getword(char *word, int lim, FILE *fp, int *line_num) {
	int c;
	char *w = word;

	while (isspace(c = fgetc(fp))) {  
		if (c == '\n') {
			(*line_num)++;  // Increment line number on newline
		}
	}

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

/* Print tree in-order with word and line numbers */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%s: ", p->word);
		for (int i = 0; i < p->line_count; i++) {
			printf("%d%s", p->lines[i], (i < p->line_count - 1) ? ", " : "");
		}
		printf("\n");
		treeprint(p->right);
	}
}

/* Free memory allocated for tree */
void freetree(struct tnode *p) {
	if (p != NULL) {
		freetree(p->left);
		freetree(p->right);
		free(p->word);
		free(p);
	}
}

/* Main function to process file input */
int main(int argc, char *argv[]) {
	struct tnode *root = NULL;
	char word[MAXWORD];
	int line_number = 1;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return 1;
	}

	FILE *inputFile = fopen(argv[1], "r");
	if (inputFile == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (getword(word, MAXWORD, inputFile, &line_number) != EOF) {
		if (isalpha(word[0]) && !is_noise_word(word)) {
			root = addtree(root, word, line_number);
		}
	}

	fclose(inputFile);

	printf("\nCross Reference List:\n");
	treeprint(root);
	freetree(root);

	return 0;
}

