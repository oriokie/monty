#include "monty.h"
/**
 * push_stack - pushes an element to the stack (at the beginning)
 * @stack: the pointer to the stack
 * @line_number: the line number (unused)
 * Return: void
 */
void push_stack(stack_t **stack, unsigned int line_number
								__attribute__((unused)))
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int i = 0;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (data.args[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", data.line_number);
		free_data(), free(new_node);
		exit(EXIT_FAILURE);
	}
	if (data.args[1][i] == '-')
		i++;
	while (data.args[1][i] != '\0')
	{
		if (isdigit(data.args[1][i]) == 0)
		{
		fprintf(stderr, "L%d: usage: push integer\n", data.line_number);
		free_data(), free(new_node);
		exit(EXIT_FAILURE);
		}
		i++;
	}
	new_node->n = atoi(data.args[1]);
	if (*stack == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = NULL;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
