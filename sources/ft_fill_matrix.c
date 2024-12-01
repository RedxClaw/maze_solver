#include "presets.h"

Maze ft_fill_matrix(char *file_directory)
{
	FILE *fptr = fopen(file_directory, "r");

	if (!fptr) exit(EXIT_FAILURE);

	Maze maze;
	fscanf(fptr, "%d %d", &(maze.heigth), &(maze.width));

	char *c = (char *)malloc(maze.width);
	ft_create_matrix(&maze);

	int i = 0, j = 0;
	int count = 0;
	while (fgets(c, maze.width + 1, fptr)) {
		j = 0;
		for (int l = 0; l < ft_strlen(c); l++) {
			if ((c[l] == '0' || c[l] == '1') && count) {
				maze.matrix[i][j] = (int)c[l] - 48;
				j++;
			}
		}
		if (j) i++;

		count = 1;
	}

	free(c);

	return (maze);
}