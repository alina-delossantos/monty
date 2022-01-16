#include "monty.h"

/**
 * swap_fx - swap_fxs the data in the first two nodes
 * @h: Pointer to the top of the stack
 * @ln_nbr: line number
 * Return: line number
 */
void swap_fx(stack_t **h, unsigned int ln_nbr)
{
	int holder;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder = (*h)->n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = holder;
}

/**
 * add_fx - Adds the first two nodes on the stack, removes first node
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void add_fx(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder->next->n += holder->n;
	holder->next->prev = NULL;
	*h = holder->next;
	free(holder);
}

/**
 * sub_fx - subtracts the top element of the stack from the second top element
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void sub_fx(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub_fx, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder->next->n -= holder->n;
	holder->next->prev = NULL;
	*h = holder->next;
	free(holder);
}

/**
 * div_fx - divides the second top element of the stack by the top element
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void div_fx(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	if (holder->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder->next->n /= holder->n;
	holder->next->prev = NULL;
	*h = holder->next;
	free(holder);
}

/**
 * mul_fx - multiplies the second top element of the stack with the top element 
 * @h: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void mul_fx(stack_t **h, unsigned int ln_nbr)
{
	stack_t *holder = *h;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul_fx, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder->next->n *= holder->n;
	holder->next->prev = NULL;
	*h = holder->next;
	free(holder);
}
