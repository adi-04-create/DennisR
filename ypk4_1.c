#include <stdio.h>
#include <stdlib.h>

// Function to calculate the determinant of a matrix
double determinant(double *matrix, int n) {
	if (n == 1) {
		return matrix[0];  // Base case: 1×1 matrix
	}

	double det = 0;
	int sign = 1;

	// Allocate memory for minor matrix
	double *minor = (double *)calloc((n - 1) * (n - 1), sizeof(double));
	if (minor == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}

	// Expansion along the first row
	for (int col = 0; col < n; col++) {
		int minorRow = 0;
		for (int i = 1; i < n; i++) {
			int minorCol = 0;
			for (int j = 0; j < n; j++) 
			{
				if (j == col) continue;  // Skip current column
				minor[minorRow * (n - 1) + minorCol] = matrix[i * n + j];
				minorCol++;
			}
			minorRow++;
		}

		// Recursive determinant calculation
		det += sign * matrix[col] * determinant(minor, n - 1);
		sign = -sign;  // Alternate signs
	}

	free(minor);  // Free allocated memory
	return det;
}

// Function to read a matrix from user input
void readMatrix(double *matrix, int n) {
	printf("Enter the elements of %d x %d matrix:\n", n, n);
	for (int i = 0; i < n * n; i++) {
		printf("Enter %d th element : ",i);
		scanf("%lf", &matrix[i]);
	}
}

int main() {
	int n;
	printf("Enter the size of the square matrix (n): ");
	scanf("%d", &n);

	// Allocate memory for the matrix
	double *matrix = (double *)calloc(n * n, sizeof(double));
	if (matrix == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}

	readMatrix(matrix, n);

	// Compute and display determinant
	double det = determinant(matrix, n);
	printf("Determinant: %.2lf\n", det);

	free(matrix);  // Free allocated memory
	return 0;
}


