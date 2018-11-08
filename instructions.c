#include "monty.h"

/**
 * m_pall - Print all command.
 *
 * @m: monty structure
 * @line_number: current line number in the monty file
 * Return: void
 */
void m_pall(monty_t *m, unsigned int line_number)
{
	(void) line_number;
	stack_t *stack;

	stack = m->stack;
	while (stack)
	{
		printf("%i\n", stack->n);
		stack = stack->next;
	}
}

/**
 * m_push - Push command.
 *
 * @m: monty structure
 * @line_number: current line number in the monty file
 * Return: void
 */
void m_push(monty_t *m, unsigned int line_number)
{

	char *token;
	int val;
	stack_t *new;

	token = strtok_r(NULL, "\n ", &m->saveptr);
	if (!token)
	{
		printf("L<%i>: usage: push integer\n", line_number);
		return;
	}
	val = atoi(token);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		return;
	}
	new->n = val;
	new->prev = NULL;
	new->next = NULL;
	if (m->stack)
	{
		m->stack->prev = new;
		new->next = m->stack;
	}
	m->stack = new;
}
