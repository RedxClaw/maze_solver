#include "presets.h"

#define RESET "\x1B[0m"
#define WHI	  "\x1B[37m"
#define RED	  "\x1B[31m"
#define GRN	  "\x1B[32m"

void ft_show_matrix(Maze *maze)
{
	int value;

	for (int i = 0; i < maze->heigth; i++) {
		for (int j = 0; j < maze->width; j++) {
			value = max(0, maze->matrix[i][j]);
			if (!value)
				printf(WHI "%i " RESET, value);
			else if (value == 1)
				printf(RED "%i " RESET, value);
			else
				printf(GRN "%i " RESET, value);
		}
		printf("\n");
	}
	printf("\n");
}