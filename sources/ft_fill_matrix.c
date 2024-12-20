#include "presets.h"

Maze ft_fill_matrix(char *file_directory)
{
	FILE *fptr = fopen(file_directory, "r");

	if (!fptr) exit(EXIT_FAILURE);

	Maze maze;
	fscanf(fptr, "%d %d\n", &(maze.heigth), &(maze.width));

	char *c = (char *)malloc(maze.width+1);
	ft_create_matrix(&maze);

	int i = 0, j = 0;
	while (fgets(c, maze.width + 1, fptr)) {
		j = 0;
		for (size_t l = 0; l < strlen(c); l++) {
			if ((c[l] == '0' || c[l] == '1')) {
				maze.matrix[i][j] = (int)c[l] - 48;
				j++;
			}
		}
		if (j) i++;
	}

	free(c);
	fclose(fptr);

	return (maze);
}