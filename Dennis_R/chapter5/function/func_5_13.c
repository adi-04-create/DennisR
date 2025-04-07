#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_LINES 10  // Default number of lines to print

void print_last_n_lines(const char *filename, int n) {
	FILE *fp = fopen(filename, "r");
	if (!fp) {
		perror("Error opening file");
		return;
	}

	fseek(fp, 0, SEEK_END); // Move to end of file
	long file_size = ftell(fp);
	int count = 0;
	char ch;

	// Start reading backwards
	for (long i = file_size - 1; i >= 0; i--) {
		fseek(fp, i, SEEK_SET);
		ch = fgetc(fp);

		if (ch == '\n') {
			count++;
			if (count == n + 1)  // Stop when n+1 newlines are found
				break;
		}
	}

	// Print the last `n` lines
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), fp)) {
		printf("%s", buffer);
	}

	fclose(fp);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename> [num_lines]\n", argv[0]);
		return 1;
	}

	int n = (argc == 3) ? atoi(argv[2]) : DEFAULT_LINES;
	if (n <= 0) {
		fprintf(stderr, "Invalid number of lines\n");
		return 1;
	}

	print_last_n_lines(argv[1], n);
	return 0;
}
