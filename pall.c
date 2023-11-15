#include "monty.h"
/**
 * print_stack - prints the stack
 * @stack: the pointer to the stack
 * @line_number: the line number (unused)
*/
void print_stack(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
