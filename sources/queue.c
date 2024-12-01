#include <stdio.h>

#include "data.h"

int ft_enQueue(Queue *q, struct qNode *previous, Data data)
{
	if (q == NULL) return -1;
	struct qNode *new_node = (struct qNode *)malloc(sizeof(struct qNode));
	if (new_node == NULL) return -1;

	new_node->data = data;
	new_node->previous = previous;
	new_node->next = NULL;

	if (q->head == NULL) {
		q->head = new_node;
	}
	else {
		q->tail->next = new_node;
	}
	if (q->cursor == NULL) {
		q->cursor = new_node;
	}
	
	q->tail = new_node;

	q->size++;

	return (0);
}

struct qNode *ft_deQueue(Queue *q)
{
	if (q == NULL || q->cursor == NULL) return NULL;

	struct qNode *node = q->cursor;

	q->cursor = node->next;

	return (node);
}

int ft_isempty(Queue *q)
{
	if (q == NULL || q->head == NULL) return 1;

	return q->size == 0;
}

void ft_clearqueue(Queue *q)
{
	struct qNode *temp;
	while (q->head != NULL) {
		temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
}