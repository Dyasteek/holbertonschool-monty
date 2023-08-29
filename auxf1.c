#include "monty.h"

int arg = 0;

/**
 * stk_push - pushes a value to the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void push(stack_t **stack)
{
	stack_t *new, *temp = *stack;

	new = malloc(sizeof(stack_t) + 1);
	if (new == NULL)
	{
		fprintf(stderr, "Line: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	new->n = arg;
	new->next = temp;
	new->prev = NULL;
	if (temp != NULL)
	{
		temp->prev = new;
	}
	*stack = new;
}

/**
 * pall - prints all values on the stack
 *
 * @stack: head of the stack
 * @line: actual line
 * Return: void
 */

void pall(stack_t **stack)
{
	stack_t *temp = *stack;

	if (*stack != NULL)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
		free(temp);
	}
}
