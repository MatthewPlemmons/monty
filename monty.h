#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct monty_s - contains variables helpful for parsing monty file
 * @saveptr: string of the current line in the monty file
 * @stack: pointer to a doubly linked list
 *
 */
typedef struct monty_s
{
	char *saveptr;
	stack_t *stack;
} monty_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_t *m, unsigned int line_number);
} instruction_t;

void m_push(monty_t *m, unsigned int line_number);
void m_pall(monty_t *m, unsigned int line_number);

#endif
