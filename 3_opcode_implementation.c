#include "monty.h"

/**
 * mod_fx - computes the rest of the division of the second top element
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void mod_fx(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod_fx, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	if (holder->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder->next->n %= holder->n;
	holder->next->prev = NULL;
	*h = holder->next;
	free(holder);
}

/**
 * pchar - prints the char at the top of the stack
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void pchar(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	if (holder->n < 0 || holder->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	putchar(holder->n);
	putchar('\n');
}

/**
 * pstr - prints the string starting at the top of the stack
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void pstr(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	while (holder != NULL && !(holder->n <= 0 || holder->n > 127))
	{
		putchar(holder->n);
		holder = holder->next;
	}
	ln_nbr = ln_nbr;
	putchar('\n');
}
