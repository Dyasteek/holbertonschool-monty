#include "monty.h"
int arg;
/**
 * readin - read the input from the file
 *
 * @name: name of the file
 * Return: array of strings with opcodes and arguments
 */

char *readin(const char *name)
{
	int fd;
	char *text;
	unsigned int size;
	struct stat st;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	fstat(fd, &st);
	size = st.st_size + 1;
	text = malloc(sizeof(char) * size);
	if (text == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	read(fd, text, size);
	text[size - 1] = '\0';
	close(fd);
	return (text);
}

/**
 * readtext - reads the text and separate it into lines
 *
 * @text: text to separate
 * Return: Array of strings
 */

char **readtext(char *text)
{
	int a, linu = 0;
	char **lines;

	for (a = 0; text[a] != '\0'; a++)
		if (text[a] == '\n' && text[a + 1] != '\n')
			linu++;
	lines = malloc(sizeof(char *) * (linu + 1));
	if (lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(lines);
		exit(EXIT_FAILURE);
	}
	lines[0] = strtok(text, "\n");
	for (a = 1; a < linu; a++)
	{
		lines[a] = strtok(NULL, "\n");
	}
	lines[a] = NULL;
	return (lines);
}

/**
 * rdline - reads te command from the line
 *
 * @line: line to read
 * @linu: line number
 * @stack: the stack
 * @f1: element to free
 * @f2: element to free
 * Return: comand and argument
 */

char *rdline(char *line, unsigned int linu, stack_t **stack, char *e1, char **e2)
{
	char *word, *num;
	int a, b = 0;

	for (a = 0; line[a] != '\0'; a++)
		if (line[a] != ' ')
			b++;
	if (b == 0)
		word = " ";
	else
		word = strtok(line, " ");
	if (strcmp(word, "push") != 0)
		arg = 0;
	else
	{
		num = strtok(NULL, " ");
		if (num == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linu);
			free_nudes(stack);
			free(e1);
            free(e2);
			exit(EXIT_FAILURE);
		}
		for (a = 0; num[a] != '\0'; a++)
		{
			if (num[a] < '0' || num[a] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", linu);
				free_nudes(stack);
				free(e1);
                free(e2);
				exit(EXIT_FAILURE);
			}
		}
		arg = atoi(num);
	}
	return (word);
}