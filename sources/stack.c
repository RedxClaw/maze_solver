#include "data.h"

void ft_sClearstack(sNode **stack)
{
	sNode *temp;

	while (*stack) {
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

int ft_sIsempty(sNode *stack)
{
	if (stack) return (0);

	return (1);
}

void ft_sPop(sNode **stack)
{
	sNode *temp;

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}

void ft_sPush(sNode **stack, Data data)
{
	sNode *new_node;

	new_node = (sNode *)malloc(sizeof(sNode));
	if (!new_node) exit(EXIT_FAILURE);

	new_node->data = data;

	if (ft_sIsempty(*(stack)))
		new_node->next = NULL;
	else
		new_node->next = *(stack);
	*(stack) = new_node;
}

Data ft_sTop(sNode *stack)
{
	return (stack->data);
}