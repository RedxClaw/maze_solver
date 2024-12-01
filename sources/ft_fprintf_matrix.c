#include "presets.h"

void ft_fprintf_matrix(Maze *maze, int iteration, double elapsedTime, char *output_directory)
{
	int	  value;
	FILE *fptr = fopen(output_directory, "w");
	if (!fptr) exit(EXIT_FAILURE);

	fprintf(fptr, "%.3f %i\n", elapsedTime, iteration);

	for (int i = 0; i < maze->heigth; i++) {
		for (int j = 0; j < maze->width; j++) {
			value = max(0, maze->matrix[i][j]);
			if (!value)
				fprintf(fptr, "%i ", value);
			else if (value == 1)
				fprintf(fptr, "%i ", value);
			else
				fprintf(fptr, "%i ", value);
		}
		fprintf(fptr, "\n");
	}
	fprintf(fptr, "\n");

	fclose(fptr);
}