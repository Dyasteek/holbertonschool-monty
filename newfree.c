#include "monty.h"

/**
 * free_node - Free a list.
 */
void free_nudes(stack_t **stack)
{
	stack_t *tmp = *stack, *tmp2;

	if (*stack != NULL)
	{
		while (tmp != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
	}
}