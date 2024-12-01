#include "presets.h"

int ft_get_degree(Maze *maze, int i, int j)
{
	int degree;

	degree = 1;

	if (i && !maze->matrix[bound(i - 1, maze->heigth)][j]) {
		degree *= 2;
	}
	if (i != maze->heigth - 1 && !maze->matrix[bound(i + 1, maze->heigth - 1)][j]) {
		degree *= 5;
	}
	if (j && !maze->matrix[i][bound(j - 1, maze->width)]) {
		degree *= 7;
	}
	if (j != maze->width - 1 && !maze->matrix[i][bound(j + 1, maze->width - 1)]) {
		degree *= 3;
	}
	return (degree);
}