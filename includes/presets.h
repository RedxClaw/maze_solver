#ifndef PRESETS_H_
#define PRESETS_H_

#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "data.h"

#define SUCCESS 1
#define FAILURE 0

#define max(A, B) ((A) > (B) ? (A) : (B))
#define bound(X, a) ((X) < 0 ? 0 : ((X) < (a) ? (X) : (a)))

void ft_create_matrix(Maze *maze);
Maze ft_fill_matrix(char *file_directory);
void ft_show_matrix(Maze *maze);
void ft_free_matrix(Maze *maze);
void ft_find_start(Maze *maze);

int ft_get_degree(Maze *maze, int i, int j);
int ft_is_solved(Maze *maze, int i, int j);

void ft_fprintf_matrix(Maze *maze, int iteration, double elapsedTime, char *output_directory);

int backtrack(Maze *maze, int debug);
int branch(Maze *maze, int debug);

double ft_gettime(struct timeval t1, struct timeval t2);

#endif