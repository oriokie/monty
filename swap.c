#include "monty.h"
/**
 * swap_toptwo - swaps the top two elements of the stack
 * @stack: the pointer to the stack
 * 	@line_number: the line number
 * Return: void
*/
void swap_toptwo(stack_t **stack,
	unsigned int line_number __attribute__((unused)))
{
	stack_t *first;
	stack_t *second;
	/* Check if the stack has less than two elements */
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", data.line_number);
		free_data();
		exit(EXIT_FAILURE);
	}
	/* Get the first and second elements of the stack*/
	first = *stack;
	second = (*stack)->next;

	/* Swap the first and second elements of the stack */
	first->next = second->next;
	if (first->next)
		first->next->prev = first;

	second->prev = first->prev;
	second->next = first;

	if (first->prev)
		first->prev->next = second;

	first->prev = second;

	/* Update the stack pointer to the new top element*/
	*stack = second;
}