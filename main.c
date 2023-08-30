#include "monty.h"

/**
 * main - reads and interprets monty code
 *
 * @argc: ammount of arguments
 * @argv: arguments given to the function
 * Return: 0 if complete
 */
int main(int argc, char **argv)
{
	char **lines, *text, *word;
	stack_t *stack = NULL;
	unsigned int idx, a;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
        {" ", nop},
		{"nop", nop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	text = readin(argv[1]);
	lines = readtext(text);
	for (idx = 0; lines[idx] != NULL; idx++)
	{
		word = rdline(lines[idx], idx + 1, &stack, text, lines);
		for (a = 0; instruction[a].opcode != NULL; a++)
		{
			if (strcmp(word, instruction[a].opcode) == 0)
			{
				instruction[a].f(&stack, idx + 1);
				break;
			}
		}
		if (instruction[a].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", idx + 1, word);
			free(lines);
			free(text);
			free_nudes(&stack);
			exit(EXIT_FAILURE);
		}
	}
	free(text);
    free(lines);
	free_nudes(&stack);
	return (0);
}