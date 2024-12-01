#include "presets.h"

int branch(Maze *maze, int debug)
{
	Queue		  q;
	Data		  data, temp;
	struct qNode *node;
	int			  iteration;

	q.head = NULL;
	q.cursor = NULL;
	q.tail = NULL;
	q.size = 0;

	data.i = maze->start[0];
	data.j = maze->start[1];

	iteration = 0;

	if (ft_enQueue(&q, NULL, data)) exit(EXIT_FAILURE);

	while (!ft_is_solved(maze, data.i, data.j)) {
		iteration++;
		node = ft_deQueue(&q);
		data = node->data;
		data.degree = ft_get_degree(maze, data.i, data.j);

		if (data.degree % 2 == 0) {
			temp = data;
			temp.i--;
			ft_enQueue(&q, node, temp);
			maze->matrix[data.i][data.j] = 2;
		}
		if (data.degree % 5 == 0) {
			temp = data;
			temp.i++;
			ft_enQueue(&q, node, temp);
			maze->matrix[data.i][data.j] = 2;
		}
		if (data.degree % 3 == 0) {
			temp = data;
			temp.j++;
			ft_enQueue(&q, node, temp);
			maze->matrix[data.i][data.j] = 2;
		}
		if (data.degree % 7 == 0) {
			temp = data;
			temp.j--;
			ft_enQueue(&q, node, temp);
			maze->matrix[data.i][data.j] = 2;
		}

		if (debug) ft_show_matrix(maze);
	}

	for (int i = 0; i < maze->heigth; i++) {
		for (int j = 0; j < maze->width; j++) {
			maze->matrix[i][j] = maze->matrix[i][j] == 1 ? 1 : 0;
		}
	}

	while (node != NULL) {
		maze->matrix[node->data.i][node->data.j] = 2;
		node = node->previous;
	}

	ft_clearqueue(&q);

	maze->matrix[data.i][data.j] = 2;
	if (debug) ft_show_matrix(maze);

	return (iteration);
}