#include "presets.h"

int backtrack(Maze *maze, int debug)
{
	sNode *stack = NULL;
	Data data;
	int iteration;

	data.i = maze->start[0];
	data.j = maze->start[1];
	data.degree = ft_get_degree(maze, data.i, data.j);

	iteration = 0;

	ft_sPush(&stack, data);

	while (!ft_is_solved(maze, data.i, data.j))
	{
		iteration++;
		data = ft_sTop(stack);
		if (data.degree < 2)
		{
			maze->matrix[data.i][data.j] = -1;
			ft_sPop(&stack);
			data = ft_sTop(stack);
			stack->data.degree = ft_get_degree(maze, data.i, data.j);
			if (debug)
				ft_show_matrix(maze);
			continue;
		}
		else if (!(data.degree % 2))
		{
			maze->matrix[data.i][data.j] = 2;
			data.i--;
		}
		else if (!(data.degree % 3))
		{
			maze->matrix[data.i][data.j] = 2;
			data.j++;
		}
		else if (!(data.degree % 5))
		{
			maze->matrix[data.i][data.j] = 2;
			data.i++;
		}
		else if (!(data.degree % 7))
		{
			maze->matrix[data.i][data.j] = 2;
			data.j--;
		}

		if (debug)
			ft_show_matrix(maze);

		data.degree = ft_get_degree(maze, data.i, data.j);
		ft_sPush(&stack, data);
	}

	maze->matrix[data.i][data.j] = 2;
	ft_sClearstack(&stack);

	return (iteration);
}