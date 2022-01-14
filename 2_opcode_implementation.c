#include "monty.h"

/**
 * swap_fx - swap_fxs the data in the first two nodes
 * @header_pointer: Pointer to the top of the stack
 * @ln_nbr: line number
 * Return: line number
 */
void swap_fx(stack_t ***header_pointer, unsigned int ln_nbr)
{
	int holder;

	if (*header_pointer == NULL || (*header_pointer)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap_fx, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder = (*header_pointer)->n;
	(*header_pointer)->n = (*header_pointer)->next->n;
	(*header_pointer)->next->n = holder;
}

/**
 * add - Adds the first two nodes on the stack, removes first node
 * @header_pointer: Pointer to the top of the stack
 * @ln_nbr: line count
 */
void add(stack_t ***header_pointer, unsigned int ln_nbr)
{
	stack_t *header_pointerolder = *header_pointer;

	if (*header_pointer == NULL || (*header_pointer)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	holder->next->n += holder->n;
	holder->next->prev = NULL;
	*header_pointer = holder->next;
	free(holder);
}
