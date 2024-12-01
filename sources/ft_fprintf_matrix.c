#include "presets.h"

void ft_fprintf_matrix(Maze *maze, int iteration, double elapsedTime, char *output_directory)
{
	FILE *fptr = fopen(output_directory, "w");
	if (!fptr) exit(EXIT_FAILURE);

	fprintf(fptr, "%.3f %i\n", elapsedTime, iteration);

	for (int i = 0; i < maze->heigth; i++) {
		for (int j = 0; j < maze->width; j++) {
			fprintf(fptr, "%i ", max(0, maze->matrix[i][j]));
		}
		fprintf(fptr, "\n");
	}
	fprintf(fptr, "\n");

	fclose(fptr);
}