#include "monty.h"

/**
 * execute_command - Checks if `line` is a valid command and executes it.
 *
 * @m: monty_t structure
 * @line: command to execute
 * @line_number: current line number of the monty file
 * Return: void
 */
void execute_command(monty_t *m, char *line, unsigned int line_number)
{
	instruction_t *instr;
	char *token;

	instruction_t instructions[] = {
		{"push", m_push},
		{"pall", m_pall},
		{NULL, NULL}
	};

	token = strtok_r(line, "\n ", &m->saveptr);
	if (token)
	{
		for (instr = instructions; instr->opcode; ++instr)
		{
			if (strcmp(token, instr->opcode) == 0)
			{
				instr->f(m, line_number);
				return;
			}
		}
		printf("error: opcode `%s` not found.\n", token);
	}
	printf("error: invalid token\n");
}


/**
 * parse_monty_file - Parse an opened monty file.
 *
 * @file: file to parse
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int parse_monty_file(FILE *file)
{
	monty_t *m;
	stack_t *tmp;
	stack_t *curr;
	char *line;
	size_t len;
	unsigned int line_number;

	m = malloc(sizeof(monty_t));
	if (!m)
	{
		return (EXIT_FAILURE);
	}
	m->saveptr = NULL;
	m->stack = NULL;

	line = NULL;
	len = 0;
	line_number = 0;
	while (getline(&line, &len, file) != -1)
	{
		execute_command(m, line, line_number);
		++line_number;
	}

	/* Free memory */
	tmp = m->stack;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		free(curr);
	}
	/*free(m->stack);*/
	free(m);
	free(line);
	return (EXIT_SUCCESS);
}

/**
 * main - Monty interpreter.
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		printf("Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}

	if (parse_monty_file(file) == EXIT_FAILURE)
	{
		exit(EXIT_FAILURE);
	}

	fclose(file);
	exit(EXIT_SUCCESS);
}
