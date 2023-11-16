#include "monty.h"
/**
 * print_topstack - function that prints the top element of
 * the stack
 * @stack: the pointer to the stack
 * @line_number: the line number (unused)
*/
void print_topstack(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *head;

	head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", data.line_number);
		free_data(), free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
