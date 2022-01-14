 #include "monty.h"

/**
 * arg_ck - cks nbr of argc
 * @ac: argument count
 */
void arg_ck(int ac)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * willy - free memory
 * @ln: memory allocated
 * @head: head
 * @file: file
 * Return: void
 */
void willy(char *ln, stack_t **head, FILE *file)
{
	free(ln);
	free_nodes(head);
	fclose(file);
}
/**
 * _isdigit - checks if nbr
 * @str: string
 * Return: 0 on sucess, else -1
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '-')
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (0);
}

#include "monty.h"

/**
 * free_nodes - free all nodes
 * @head: head node
 * Return: void
 */
void free_nodes(stack_t **head)
{
	stack_t *temp;

	temp = *head;

	while (temp)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
