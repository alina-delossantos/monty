#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* functions */

/* aux_fxs */

void arg_ck(int ac);
void willy(char *ln, stack_t **head, FILE *file);
int _isdigit(char *str);
void free_nodes(stack_t **head);

/* executioner */

int executioner(char *string, stack_t **head, unsigned int ln_nbr);

/* opcode_implementation.c */

stack_t *push_fx(stack_t **head, int n);
void pall_fx(stack_t **head_pointer, unsigned int ln_nbr);
void pint_fx(stack_t **header_pointer, unsigned int ln_nbr);
void pop_fx(stack_t **header_pointer, unsigned int ln_nbr);
void nop_fx(stack_t **h, unsigned int ln_nbr);

/* 2_opcode_implementation */

void swap_fx(stack_t **h, unsigned int ln_nbr);
void add_fx(stack_t **h, unsigned int ln_nbr);
void sub_fx(stack_t **h, unsigned int ln_nbr);
void div_fx(stack_t **h, unsigned int ln_nbr);

#endif
