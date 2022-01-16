#include "monty.h"

/**
 * executioner - cks thru array of stringuct and matched fx
 * @string: input string
 * @head: head
 * @ln_nbr: line number
 * Return: 1 if fx matched, -1 if not
 */
int executioner(char *string, stack_t **head, unsigned int ln_nbr)
{
	instruction_t inst[] = {
		{"pall", pall_fx}, {"pint", pint_fx},
		{"pop", pop_fx}, {"swap", swap_fx},
		{"add", add_fx}, {"nop", nop_fx}, {"sub", sub_fx},
		{"div", div_fx}, {"mul", mul_fx}, {NULL, NULL}
	};

	int i;

	for (i = 0; (inst[i].opcode != NULL); i++)
	{
		if (strcmp(string, inst[i].opcode) == 0)
		{
			(inst[i].f)(head, ln_nbr);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln_nbr, string);
	exit(EXIT_FAILURE);
}
