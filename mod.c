#include "monty.h"
/**
 * mod_toptwo - function that computes the remainder of the
 * division of the top two elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void mod_toptwo(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	int first, second, result = 0;
	stack_t *temp = *stack;

	/* The stack should contain more than one element */
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", data.line_number);
		free_data();
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;
	result = first % second;
	temp->next->n = result;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
