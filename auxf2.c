#include "monty.h"

/**
 * pint - print the value in the top of the stack
 *
 * @stack: the stack
 * @line: line number
 * Return: void
 */

void pint(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", temp->n);
	}
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: the stack
 * @line: line number
 * Return: void
 */

void pop(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack, *temp2;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	free(temp);
	if (temp2 != NULL)
	{
		temp2->prev = NULL;
	}
	*stack = temp2;
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: the stack
 * @line: line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack, *temp2;

	if (*stack == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	temp->prev = temp2;
	temp2->prev = NULL;
	temp2->next = temp;
	*stack = temp2;
}

/**
 * addm - add the top two elements of the stack
 *
 * @stack: stack of the stack
 * @line: line number
 * Return: void
 */

void add(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack, *temp2;

	if (*stack == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp2 = temp->next;
	temp2->n = temp->n + temp2->n;
	temp2->prev = NULL;
	free(temp);
	*stack = temp2;
}

/**
 * nop - Does nothing.
 * @stack: Top of the stack.
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)*stack;
	(void)line;
}