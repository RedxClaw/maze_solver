#include "presets.h"

void ft_create_matrix(Maze *maze)
{
	maze->matrix = (int **)malloc(maze->heigth * sizeof(int *));
	for (int i = 0; i < maze->heigth; i++)
		maze->matrix[i] = (int *)malloc(maze->width * sizeof(int));
}