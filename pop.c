#include "monty.h"
/**
 * pop_element - pops the top element from the stack
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void pop_top(stack_t **stack,
	unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* stack has only one element */
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
