#include "presets.h"

void ft_find_start(Maze *maze)
{
	int i = 0, j = 0;

	while (maze->matrix[i][j]) {
		if (i < maze->heigth - 1 && !j)
			i++;
		else if (i == maze->heigth - 1 && j < maze->width - 1)
			j++;
		else if (i && j == maze->width - 1)
			i--;
		else if (!i && j)
			j--;
		else
			exit(EXIT_FAILURE);
	}
	maze->start[0] = i;
	maze->start[1] = j;
}