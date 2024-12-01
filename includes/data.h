#ifndef DATA_H
#define DATA_H

#include <stdlib.h>

typedef struct Data {
	int i, j;
	int degree;
} Data;

typedef struct sNode {
	Data		  data;
	struct sNode *next;
} sNode;

struct qNode {
	Data		  data;
	struct qNode *previous;
	struct qNode *next;
};

typedef struct Queue {
	int			  size;
	struct qNode *head;
	struct qNode *cursor;
	struct qNode *tail;
} Queue;

typedef struct Maze {
	int	  heigth, width;
	int	 *start;
	int **matrix;
} Maze;

void ft_sPush(sNode **stack, Data Data);
void ft_sPop(sNode **stack);
Data ft_sTop(sNode *stack);
void ft_sClearstack(sNode **stack);
int	 ft_sIsempty(sNode *stack);

int			  ft_enQueue(Queue *q, struct qNode *previous, Data data);
struct qNode *ft_deQueue(Queue *q);
int			  ft_isempty(Queue *q);
void		  ft_clearqueue(Queue *q);
void		  ft_cutqueue(Maze **maze, Queue *q);

#endif