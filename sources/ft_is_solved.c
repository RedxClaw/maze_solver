#include "presets.h"

int ft_is_solved(Maze *maze, int i, int j)
{
	if ((i == 0 || i == maze->heigth - 1 || j == 0 || j == maze->width - 1) &&
		(i != maze->start[0] || j != maze->start[1]))
		return (1);

	return (0);
}