#include "monty.h"
/**
 * push - push an element to the stack
 *
 * @stack: the stack
 * @line: actual line
 * @arg: value to be pushed on the stack
 * Return: void
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line)
{
    stack_t *new, *tmp= *stack;
	int arg = 0;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = arg;
    new->next = tmp;
    new->prev = NULL;
    if (tmp != NULL)
    {
        tmp->prev = new;
    }
    *stack = new;
}

/**
 * pall - prints all values on the stack
 *
 * @stack: the stack
 * @line: actual line
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *stack;

	if (*stack != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
