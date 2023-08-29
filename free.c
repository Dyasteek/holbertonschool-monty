#include "monty.h"

/**
 * free_node - Free a list.
 */
void free_node(stack_t *stack)
{
	if (!stack)
		return;

	while ((*stack).next != NULL)
	{
		stack = stack->next;
		free((*stack).prev);
	}
	free(stack);
}