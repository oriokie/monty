#include "monty.h"
/**
 * free_data - frees the data
 * Return: void
*/
void free_data(void)
{
	free(data.line);
	data.line = NULL;
	free(data.args);
	data.args = NULL;
	fclose(data.file);
}
/**
 * free_stack - frees the stack
 * @stack: the pointer to the stack
 * Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *tmp;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
