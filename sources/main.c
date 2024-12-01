#include "presets.h"

int main(int argc, char *argv[])
{
	Maze maze;
	int debug, iteration;

	struct timeval t1, t2;
	debug = !strcmp(argv[argc - 1], "debug");
		

	gettimeofday(&t1, NULL);
	maze = ft_fill_matrix(argv[1]);
	ft_find_start(&maze);
	printf("Solving maze with backtracking algorithm\n");
	iteration = backtrack(&maze, debug);
	gettimeofday(&t2, NULL);
	ft_fprintf_matrix(&maze, iteration, ft_gettime(t1, t2), "output_backtracking.txt");
	printf("Time elapsed for backtracking algorithm : %.3f ms\n", ft_gettime(t1, t2));
	printf("It took %i iteration(s) to solve the maze\n", iteration);

	ft_free_matrix(&maze);

	printf("\n------------------------\n\n");

	gettimeofday(&t1, NULL);
	maze = ft_fill_matrix(argv[1]);
	ft_find_start(&maze);
	printf("Solving maze with branch and bound algorithm\n");
	iteration = branch(&maze, debug);
	ft_fprintf_matrix(&maze, iteration, ft_gettime(t1, t2), "output_branchAndBound.txt");
	gettimeofday(&t2, NULL);
	printf("Time elapsed for branch and bound algorithm : %.3f ms\n", ft_gettime(t1, t2));
	printf("It took %i iteration(s) to solve the maze\n", iteration);

	ft_free_matrix(&maze);
}