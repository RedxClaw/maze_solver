#include "presets.h"

void ft_free_matrix(Maze *maze)
{
	for (int i = 0; i < maze->heigth; i++)
		free(maze->matrix[i]);

	free(maze->matrix);
}