#include "monty.h"
/**
 * add_toptwo - adds the top two elements of the stack
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void add_toptwo(stack_t **stack, unsigned int line_number)
{
	int first;
	int second;
	int sum = 0;
	stack_t *temp = *stack;

	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", data.line_number);
		free_data();
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;
	sum = first + second;

	temp = *stack;
	temp->next->n = sum;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
