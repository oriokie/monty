#include "monty.h"
/**
 * sub_toptwo  - function that subtracts the tope element of the stack
 * from the second top element
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void sub_toptwo(stack_t **stack, unsigned int line_number)
{
	int first;
	int second;
	int sub = 0;
	stack_t *temp = *stack;

	(void) line_number;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", data.line_number);
		free_data();
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;
	sub = second - first;

	temp = *stack;
	temp->next->n = sub;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
