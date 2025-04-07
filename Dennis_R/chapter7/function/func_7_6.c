#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
		return 1;
	}

	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");

	if (!fp1 || !fp2) {
		perror("Error opening files");
		return 1;
	}

	char line1[MAXLINE], line2[MAXLINE];
	int lineno = 1;

	while (fgets(line1, MAXLINE, fp1) && fgets(line2, MAXLINE, fp2)) {
		if (strcmp(line1, line2) != 0) {
			printf("Files differ at line %d:\n", lineno);
			printf("File1: %s", line1);
			printf("File2: %s", line2);
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
		lineno++;
	}

	// Check if one file has more lines
	if (fgets(line1, MAXLINE, fp1)) {
		printf("File1 has extra line at %d: %s", lineno, line1);
	} else if (fgets(line2, MAXLINE, fp2)) {
		printf("File2 has extra line at %d: %s", lineno, line2);
	} else {
		printf("Files are identical.\n");
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

