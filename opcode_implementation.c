#include "monty.h"



/**
 * push_fx - pushes an element to the stack
 * @head: head
 * @n: int
 * Return: new node
 */
stack_t *push_fx(stack_t **head, int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (head == NULL || new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
	return (new);
}



/**
 * pall_fx - prints all the values on the stack
 * @head_pointer: pointer to head
 * @ln_nbr: line number of .m file
 * Return: void
 */
void pall_fx(stack_t **head_pointer, unsigned int ln_nbr)
{
	stack_t *temp = *head_pointer;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	ln_nbr = ln_nbr;
}


/**
 * pint_fx - Prints the value at the top of the stack
 * @h: pointer to head
 * @ln_nbr: line number
 * Return: void
 */
void pint_fx(stack_t **h, unsigned int ln_nbr)
{
	if ((*h) == NULL || h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
	ln_nbr++;
}


/**
 * pop_fx - Removes th e top element of the stack
 * @h: pointer to head
 * @ln_nbr: line number
 * Return: void
 */
void pop_fx(stack_t **h, unsigned int ln_nbr)
{
	stack_t *top = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_nbr);
		exit(EXIT_FAILURE);
	}
	if (top->next)
		top->next->prev = NULL;
	*h = top->next;
	ln_nbr++;
	free(top);
}

/**
 * nop_fx - does nothing
 * @h: pointer to top of stack
 * @ln_nbr: line number
 * Return: void
 */
void nop_fx(stack_t **h, unsigned int ln_nbr)
{
	ln_nbr = ln_nbr;
	*h = *h;
}
