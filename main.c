#include "monty.h"

/**
 * main - entry point
 * @argc: nbr of arguments
 * @argv: double pointer to input
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	size_t size;
	unsigned int ln_nbr = 1;
	char *opcode = NULL, *ins = NULL, *ln = NULL;
	stack_t *head;

	head = NULL;
	arg_ck(argc);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; ((getline(&ln, &size, fp)) != -1); ln_nbr++)
	{
		opcode = strtok(ln, "\n\t\r ");
		if (opcode != NULL)
		{
			ins = strtok(NULL, "\n\t\r ");
			if (_isdigit(ins) == 0 && strcmp("push", opcode) == 0 && opcode[0] != '#')
				push(&head, atoi(ins));
			else if (strcmp("push", opcode) != 0 && opcode[0] != '#')
				executioner(opcode, &head, ln_nbr);
			else if (opcode[0] != '#')
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln_nbr);
				exit(EXIT_FAILURE);
			}
		}
	}
	willy(ln, &head, fp);
	return (0);
}
